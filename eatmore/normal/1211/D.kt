import java.lang.Integer.parseInt
import java.lang.Long.parseLong
import java.lang.Math.min
import java.lang.System.exit

import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.HashMap
import java.util.StringTokenizer

object D {

    internal var `in`: BufferedReader? = null
    internal var out: PrintWriter? = null
    internal var tok: StringTokenizer? = null

    @Throws(Exception::class)
    internal fun solve() {
        val n = scanInt()
        val a = scanInt()
        val b = scanInt()
        val k = scanInt()
        val cnts = HashMap<Int, IntArray>()
        for (i in 0 until n) {
            var v = scanInt()
            var c = 0
            while (v % k == 0) {
                v /= k
                ++c
            }
            var vv: IntArray? = cnts[v]
            if (vv == null) {
                vv = IntArray(20)
                cnts[v] = vv
            }
            ++vv!![c]
        }
        var ans = 0
        for (vv in cnts.values) {
            if (a < b) {
                for (i in vv.size - 1 downTo 1) {
                    val cans = min(vv[i] / b, vv[i - 1] / a)
                    vv[i] -= cans * b
                    vv[i - 1] -= cans * a
                    ans += cans
                }
            } else {
                for (i in 0 until vv.size - 1) {
                    val cans = min(vv[i] / a, vv[i + 1] / b)
                    vv[i] -= cans * a
                    vv[i + 1] -= cans * b
                    ans += cans
                }
            }
        }
        out!!.print(ans)
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
    D.main(args)
}