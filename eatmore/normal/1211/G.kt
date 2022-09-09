import java.lang.Integer.parseInt
import java.lang.Long.parseLong
import java.lang.System.arraycopy
import java.lang.System.exit
import java.util.Arrays.copyOf

import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.NoSuchElementException
import java.util.StringTokenizer

object G {

    internal var `in`: BufferedReader? = null
    internal var out: PrintWriter? = null
    internal var tok: StringTokenizer? = null

    internal class IntList {

        var data = IntArray(3)
        var size = 0

        val isEmpty: Boolean
            get() = size == 0

        fun size(): Int {
            return size
        }

        operator fun get(index: Int): Int {
            if (index < 0 || index >= size) {
                throw IndexOutOfBoundsException()
            }
            return data[index]
        }

        fun clear() {
            size = 0
        }

        operator fun set(index: Int, value: Int) {
            if (index < 0 || index >= size) {
                throw IndexOutOfBoundsException()
            }
            data[index] = value
        }

        fun expand() {
            if (size >= data.size) {
                data = copyOf(data, (data.size shl 1) + 1)
            }
        }

        fun insert(index: Int, value: Int) {
            if (index < 0 || index > size) {
                throw IndexOutOfBoundsException()
            }
            expand()
            arraycopy(data, index, data, index + 1, size++ - index)
            data[index] = value
        }

        fun delete(index: Int): Int {
            if (index < 0 || index >= size) {
                throw IndexOutOfBoundsException()
            }
            val value = data[index]
            arraycopy(data, index + 1, data, index, --size - index)
            return value
        }

        fun push(value: Int) {
            expand()
            data[size++] = value
        }

        fun pop(): Int {
            if (size == 0) {
                throw NoSuchElementException()
            }
            return data[--size]
        }

        fun unshift(value: Int) {
            expand()
            arraycopy(data, 0, data, 1, size++)
            data[0] = value
        }

        fun shift(): Int {
            if (size == 0) {
                throw NoSuchElementException()
            }
            val value = data[0]
            arraycopy(data, 1, data, 0, --size)
            return value
        }
    }

    @Throws(Exception::class)
    internal fun solve() {
        val tests = scanInt()
        for (test in 0 until tests) {
            val n = scanInt()
            val c = IntArray(n)
            val d = IntArray(n)
            for (i in 0 until n) {
                c[i] = scanInt()
            }
            for (i in 0 until n) {
                d[i] = scanInt()
            }
            val edges = arrayOfNulls<IntList>(n)
            for (i in 0 until n) {
                edges[i] = IntList()
            }
            for (i in 0 until n - 1) {
                val a = scanInt() - 1
                val b = scanInt() - 1
                edges[a]!!.push(b)
                edges[b]!!.push(a)
            }
            var dif = false
            for (i in 0 until n) {
                if (c[i] != d[i]) {
                    dif = true
                    break
                }
            }
            if (!dif) {
                out!!.println("Yes")
                out!!.println("0")
                continue
            }
            val deg = IntArray(n)
            val d1 = IntList()
            for (i in 0 until n) {
                deg[i] = edges[i]!!.size
                if (deg[i] == 1) {
                    d1.push(i)
                }
            }
            val removed = BooleanArray(n)
            val rem = IntList()
            var left = n
            while (!d1.isEmpty) {
                val cur = d1.pop()
                if (c[cur] != d[cur]) {
                    rem.push(cur)
                } else {
                    removed[cur] = true
                    --left
                    for (i in 0 until edges[cur]!!.size) {
                        val next = edges[cur]!!.data[i]
                        if (!removed[next]) {
                            --deg[next]
                            if (deg[next] == 1) {
                                d1.push(next)
                            }
                        }
                    }
                }
            }
            if (rem.size != 2) {
                out!!.println("No")
                continue
            }
            val seq = IntArray(left)
            var cur = rem.data[0]
            for (i in 0 until left - 1) {
                seq[i] = cur
                removed[cur] = true
                for (j in 0 until edges[cur]!!.size) {
                    val next = edges[cur]!!.data[j]
                    if (!removed[next]) {
                        cur = next
                        break
                    }
                }
            }
            seq[left - 1] = cur
            var good = true
            for (i in 0 until left) {
                if (c[seq[i]] != d[seq[(i + left - 1) % left]]) {
                    good = false
                    break
                }
            }
            if (good) {
                out!!.println("Yes")
                out!!.println(left)
                for (i in 0 until left) {
                    out!!.print((seq[i] + 1).toString() + " ")
                }
                continue
            }
            good = true
            for (i in 0 until left) {
                if (c[seq[i]] != d[seq[(i + 1) % left]]) {
                    good = false
                    break
                }
            }
            if (good) {
                out!!.println("Yes")
                out!!.println(left)
                for (i in left - 1 downTo 0) {
                    out!!.print((seq[i] + 1).toString() + " ")
                }
                continue
            }
            out!!.println("No")
        }
    }

    @Throws(IOException::class)
    internal fun scanInt(): Int {
        return parseInt(scanString())
    }

    @Throws(IOException::class)
    internal fun scanLong(): Long {
        return parseLong(scanString())
    }

    @Throws(IOException::class)
    internal fun scanString(): String {
        while (tok == null || !tok!!.hasMoreTokens()) {
            tok = StringTokenizer(`in`!!.readLine())
        }
        return tok!!.nextToken()
    }

    @JvmStatic
    fun main(args: Array<String>) {
        try {
            `in` = BufferedReader(InputStreamReader(System.`in`))
            out = PrintWriter(System.out)
            solve()
            `in`!!.close()
            out!!.close()
        } catch (e: Throwable) {
            e.printStackTrace()
            exit(1)
        }

    }
}

fun main(args: Array<String>) {
    G.main(args)
}