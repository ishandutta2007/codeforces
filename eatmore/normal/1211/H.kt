import java.lang.Integer.parseInt
import java.lang.Long.parseLong
import java.lang.System.arraycopy
import java.lang.System.exit
import java.util.Arrays.copyOf
import java.util.Arrays.fill

import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.Arrays
import java.util.NoSuchElementException
import java.util.StringTokenizer

object H {

    internal var lim: Int = 0
    internal var edges: Array<IntList?>? = null
    internal var roots: IntList? = null
    internal var next1: IntArray? = null
    internal var next2: IntArray? = null

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
            var l = 1
            var r = n - 1
            roots = IntList()
            next1 = IntArray(n)
            next2 = IntArray(n)
            while (l < r) {
                lim = l + r shr 1
                roots!!.clear()
                fill(next1, -1)
                fill(next2, -1)
                if (dfs(0, -1, -1) <= lim) {
                    r = lim
                } else {
                    l = lim + 1
                }
            }
            lim = l
            roots!!.clear()
            fill(next1, -1)
            fill(next2, -1)
            dfs(0, -1, -1)
            val ans = IntArray(n - 1)
            val stack = IntList()
            for (i in 0 until roots!!.size) {
                stack.push(roots!!.data[i])
                do {
                    val cur = stack.pop()
                    ans[cur] = i
                    if (next1!![cur] >= 0) {
                        stack.push(next1!![cur])
                    }
                    if (next2!![cur] >= 0) {
                        stack.push(next2!![cur])
                    }
                } while (!stack.isEmpty)
            }
            out!!.println(lim)
            for (i in 0 until n - 1) {
                out!!.print((ans[i] + 1).toString() + " ")
            }
            out!!.println()
        }
    }

    internal fun dfs(cur: Int, prev: Int, upEdge: Int): Int {
        var groupCnt = edges!![cur]!!.size shr 1
        if (prev >= 0) {
            --groupCnt
        }
        val groupSize = IntArray(groupCnt)
        val groupEdge = IntArray(groupCnt)
        var totalSize = 0
        var curGroup = 0
        run {
            var i = 0
            while (i < edges!![cur]!!.size) {
                val next = edges!![cur]!!.data[i]
                if (next == prev) {
                    i += 2
                    continue
                }
                val cedge = edges!![cur]!!.data[i + 1]
                groupSize[curGroup] = dfs(next, cur, cedge)
                groupEdge[curGroup] = cedge
                totalSize += groupSize[curGroup]
                ++curGroup
                i += 2
            }
        }
        val kprev = IntArray(lim + 1)
        fill(kprev, -1)
        kprev[0] = -2
        for (i in 0 until groupCnt) {
            val csize = groupSize[i]
            for (j in lim downTo csize) {
                if (kprev[j] < 0 && kprev[j - csize] != -1) {
                    kprev[j] = i
                }
            }
        }
        var maxSize = 0
        for (i in lim downTo 0) {
            if (kprev[i] != -1) {
                maxSize = i
                break
            }
        }
        val chosen = BooleanArray(groupCnt)
        var prevC = -1
        run {
            var i = maxSize
            while (i != 0) {
                if (prevC >= 0) {
                    next2!![groupEdge[kprev[i]]] = groupEdge[prevC]
                }
                prevC = kprev[i]
                chosen[kprev[i]] = true
                i -= groupSize[kprev[i]]
            }
        }
        if (prevC >= 0) {
            roots!!.push(groupEdge[prevC])
        }
        prevC = -1
        for (i in 0 until groupCnt) {
            if (!chosen[i]) {
                if (prevC >= 0) {
                    next2!![groupEdge[i]] = groupEdge[prevC]
                }
                prevC = i
            }
        }
        if (upEdge >= 0) {
            if (prevC >= 0) {
                next1!![upEdge] = groupEdge[prevC]
            }
            return totalSize + 1 - maxSize
        } else {
            if (prevC >= 0) {
                roots!!.push(groupEdge[prevC])
            }
            return totalSize - maxSize
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