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

object F {

    internal var edges: Array<Array<IntList?>>? = null

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
        val n = scanInt()
        edges = Array(6) { Array(6) { null as IntList? } }
        for (i in 0..5) {
            for (j in 0..5) {
                edges!![i][j] = IntList()
            }
        }
        for (i in 0 until n) {
            val s = scanString()
            val a = "kotlin".indexOf(s[0])
            val b = "nkotli".indexOf(s[s.length - 1])
            edges!![a][b]!!.push(i)
        }
        dfs(0)
    }

    internal fun dfs(cur: Int) {
        for (next in 0..5) {
            while (edges!![next][cur]!!.size > 0) {
                val i = edges!![next][cur]!!.pop()
                dfs(next)
                out!!.print((i + 1).toString() + " ")
            }
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
    F.main(args)
}