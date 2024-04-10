import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

object E {
    @Throws(Exception::class)
    fun solve() {
        val tests = scanInt()
        for (test in 0 until tests) {
            val n = scanInt()
            val k = scanInt()
            val edges = arrayOfNulls<IntList>(n)
            for (i in 0 until n) {
                edges[i] = IntList()
            }
            val deg = IntArray(n)
            val dead = IntList()
            val here = BooleanArray(n)
            Arrays.fill(here, true)
            for (i in 0 until n - 1) {
                val a = scanInt() - 1
                val b = scanInt() - 1
                edges[a]!!.push(b)
                edges[b]!!.push(a)
                ++deg[a]
                ++deg[b]
            }
            for (i in 0 until n) {
                if (deg[i] <= 1) {
                    dead.push(i)
                }
            }
            if (k > dead.size) {
                out!!.println("No")
                continue
            }
            out!!.println("Yes")
            while (k < dead.size) {
                val cur = dead.pop()
                here[cur] = false
                for (i in 0 until edges[cur]!!.size) {
                    val next = edges[cur]!!.data[i]
                    if (!here[next]) {
                        continue
                    }
                    if (--deg[next] == 1) {
                        dead.push(next)
                    }
                }
            }
            var m = 0
            for (i in 0 until n) {
                if (here[i]) {
                    ++m
                }
            }
            out!!.println(m)
            for (i in 0 until n) {
                if (here[i]) {
                    out!!.print((i + 1).toString() + " ")
                }
            }
            out!!.println()
        }
    }

    @Throws(IOException::class)
    fun scanInt(): Int {
        return scanString().toInt()
    }

    @Throws(IOException::class)
    fun scanLong(): Long {
        return scanString().toLong()
    }

    @Throws(IOException::class)
    fun scanString(): String {
        while (tok == null || !tok!!.hasMoreTokens()) {
            tok = StringTokenizer(`in`!!.readLine())
        }
        return tok!!.nextToken()
    }

    var `in`: BufferedReader? = null
    var out: PrintWriter? = null
    var tok: StringTokenizer? = null
    fun main() {
        try {
            `in` = BufferedReader(InputStreamReader(System.`in`))
            out = PrintWriter(System.out)
            solve()
            `in`!!.close()
            out!!.close()
        } catch (e: Throwable) {
            e.printStackTrace()
            System.exit(1)
        }
    }

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
                data = Arrays.copyOf(data, (data.size shl 1) + 1)
            }
        }

        fun insert(index: Int, value: Int) {
            if (index < 0 || index > size) {
                throw IndexOutOfBoundsException()
            }
            expand()
            System.arraycopy(data, index, data, index + 1, size++ - index)
            data[index] = value
        }

        fun delete(index: Int): Int {
            if (index < 0 || index >= size) {
                throw IndexOutOfBoundsException()
            }
            val value = data[index]
            System.arraycopy(data, index + 1, data, index, --size - index)
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
            System.arraycopy(data, 0, data, 1, size++)
            data[0] = value
        }

        fun shift(): Int {
            if (size == 0) {
                throw NoSuchElementException()
            }
            val value = data[0]
            System.arraycopy(data, 1, data, 0, --size)
            return value
        }
    }
}

fun main() {
    E.main()
}