import java.lang.Integer.parseInt
import java.lang.Long.parseLong
import java.lang.System.exit

import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.StringTokenizer

object A {

    internal var `in`: BufferedReader? = null
    internal var out: PrintWriter? = null
    internal var tok: StringTokenizer? = null

    internal fun swap(a: IntArray, i: Int, j: Int) {
        val t = a[i]
        a[i] = a[j]
        a[j] = t
    }

    @Throws(Exception::class)
    internal fun solve() {
        val n = scanInt()
        val p = IntArray(3)
        val d = IntArray(3)
        var c = 0
        i@ for (i in 0 until n) {
            val cur = scanInt()
            for (j in 0 until c) {
                if (cur == d[j]) {
                    continue@i
                }
            }
            p[c] = i
            d[c] = cur
            if (++c == 3) {
                break
            }
        }
        if (c == 3) {
            if (d[0] > d[1]) {
                swap(p, 0, 1)
                swap(d, 0, 1)
            }
            if (d[1] > d[2]) {
                swap(p, 1, 2)
                swap(d, 1, 2)
            }
            if (d[0] > d[1]) {
                swap(p, 0, 1)
                swap(d, 0, 1)
            }
            out!!.print((p[0] + 1).toString() + " " + (p[1] + 1) + " " + (p[2] + 1))
        } else {
            out!!.print("-1 -1 -1")
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
    A.main(args)
}