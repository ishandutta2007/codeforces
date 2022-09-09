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
import java.util.BitSet
import java.util.HashMap
import java.util.NoSuchElementException
import java.util.StringTokenizer

object I {

    internal var cedges: Array<BooleanArray>? = null
    internal var nn: Int = 0
    internal var unass: Int = 0
    internal var vals: IntArray? = null

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
        val m = scanInt()
        val edges = arrayOfNulls<BitSet>(n)
        for (i in 0 until n) {
            edges[i] = BitSet(n)
        }
        for (i in 0 until m) {
            val a = scanInt() - 1
            val b = scanInt() - 1
            edges[a]!!.set(b)
            edges[b]!!.set(a)
        }
        val classes = HashMap<BitSet, IntList>()
        for (i in 0 until n) {
            var v: IntList? = classes[edges[i]]
            if (v == null) {
                v = IntList()
                classes[edges[i]!!] = v
            }
            v.push(i)
        }
        nn = classes.size
        val clss = classes.values.toTypedArray()
        cedges = Array(nn) { BooleanArray(nn) }
        for (i in 0 until nn) {
            for (j in 0 until nn) {
                if (edges[clss[i][0]]!!.get(clss[j][0])) {
                    cedges!![i][j] = true
                }
            }
        }
        vals = IntArray(nn)
        fill(vals!!, -1)
        unass = 0
        if (!go(0)) {
            throw AssertionError()
        }
        val ans = IntArray(n)
        for (i in 0 until nn) {
            for (j in 0 until clss[i].size) {
                ans[clss[i].data[j]] = vals!![i]
            }
        }
        for (i in 0 until n) {
            out!!.print(ans[i].toString() + " ")
        }
    }

    internal fun go(cur: Int): Boolean {
        if (cur == nn + unass) {
            return true
        }
        if (cur == 16) {
            return false
        }
        if (cur != 0 && nn + unass < 16) {
            ++unass
            if (go(cur + 1)) {
                return true
            }
            --unass
        }
        i@ for (i in 0 until nn) {
            if (vals!![i] < 0) {
                for (j in 0 until nn) {
                    if (vals!![j] >= 0 && cedges!![i][j] != needEdge(cur, vals!![j])) {
                        continue@i
                    }
                }
                vals!![i] = cur
                if (go(cur + 1)) {
                    return true
                }
                vals!![i] = -1
            }
        }
        return false
    }

    internal fun needEdge(i: Int, j: Int): Boolean {
        val x = i xor j
        return x and x - 1 == 0
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
    I.main(args)
}