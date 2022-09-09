import java.lang.Integer.parseInt
import java.lang.Long.parseLong
import java.lang.Math.max
import java.lang.Math.min
import java.lang.System.arraycopy
import java.lang.System.exit
import java.util.Arrays.copyOf

import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.NoSuchElementException
import java.util.StringTokenizer

object H {

    internal var n: Int = 0
    internal var k: Int = 0
    internal var edges: Array<IntList?>? = null
    internal var ans: IntList? = null

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
        n = scanInt()
        k = scanInt()
        edges = arrayOfNulls(n)
        for (i in 0 until n) {
            edges!![i] = IntList()
        }
        for (i in 0 until n - 1) {
            val a = scanInt() - 1
            val b = scanInt() - 1
            edges!![a]!!.push(b)
            edges!![a]!!.push(i)
            edges!![b]!!.push(a)
            edges!![b]!!.push(i)
        }
        ans = null
        dfs(0, -1, -1)
        out!!.println(ans!!.size)
        for (i in 0 until ans!!.size) {
            out!!.print((ans!!.data[i] + 1).toString() + " ")
        }
    }

    internal fun dfs(cur: Int, prev: Int, upEdgeId: Int): Array<IntList?>? {
        var cans = arrayOfNulls<IntList>(1)
        cans[0] = IntList()
        run {
            var i = 0
            while (i < edges!![cur]!!.size) {
                val next = edges!![cur]!!.data[i]
                if (next == prev) {
                    i += 2
                    continue
                }
                val nans = dfs(next, cur, edges!![cur]!!.data[i + 1])
                val merged = arrayOfNulls<IntList>(cans.size + nans!!.size - 1)
                for (j in merged.indices) {
                    var best = Integer.MAX_VALUE
                    val from = max(0, j - nans.size + 1)
                    val to = min(cans.size - 1, j)
                    for (k in from..to) {
                        best = min(best, cans[k]!!.size + nans[j - k]!!.size)
                    }
                    for (k in from..to) {
                        if (best == cans[k]!!.size + nans[j - k]!!.size) {
                            merged[j] = IntList()
                            for (ii in 0 until cans[k]!!.size) {
                                merged[j]!!.push(cans[k]!!.data[ii])
                            }
                            for (ii in 0 until nans[j - k]!!.size) {
                                merged[j]!!.push(nans[j - k]!!.data[ii])
                            }
                            break
                        }
                    }
                }
                cans = merged
                i += 2
            }
        }
        if (cans.size >= k) {
            var mySize = cans[k - 1]!!.size
            if (upEdgeId >= 0) {
                ++mySize
            }
            if (ans == null || ans!!.size > mySize) {
                if (ans == null) {
                    ans = IntList()
                } else {
                    ans!!.size = 0
                }
                for (i in 0 until cans[k - 1]!!.size) {
                    ans!!.push(cans[k - 1]!!.data[i])
                }
                if (upEdgeId >= 0) {
                    ans!!.push(upEdgeId)
                }
            }
        }
        if (upEdgeId >= 0) {
            val nans = arrayOfNulls<IntList>(cans.size + 1)
            arraycopy(cans, 0, nans, 1, cans.size)
            nans[0] = IntList()
            nans[0]!!.push(upEdgeId)
            return nans
        } else {
            return null
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
    H.main(args)
}