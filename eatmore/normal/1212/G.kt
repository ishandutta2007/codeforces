import java.lang.Integer.parseInt
import java.lang.Long.parseLong
import java.lang.Math.abs
import java.lang.Math.sqrt
import java.lang.System.arraycopy
import java.lang.System.exit

import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.StringTokenizer

object G {

    internal var `in`: BufferedReader? = null
    internal var out: PrintWriter? = null
    internal var tok: StringTokenizer? = null

    @Throws(Exception::class)
    internal fun solve() {
        val n = scanInt()
        val l = scanInt()
        val x = IntArray(n)
        val b = IntArray(n)
        for (i in 0 until n) {
            x[i] = scanInt()
            b[i] = scanInt()
        }
        val ans = DoubleArray(n)
        val prev = IntArray(n)
        val prevOpt = IntArray(n)
        prevOpt[n - 1] = -1
        var ll = 0.0
        var rr = 1000.0
        for (it in 0..59) {
            val mid = (ll + rr) / 2
            for (i in 0 until n) {
                val cx = x[i]
                val cb = b[i]
                var cans = sqrt(abs(cx - l).toDouble())
                var cprev = -1
                for (j in 0 until i) {
                    val nans = ans[j] + sqrt(abs(cx - x[j] - l).toDouble())
                    if (nans < cans) {
                        cans = nans
                        cprev = j
                    }
                }
                ans[i] = cans - mid * cb
                prev[i] = cprev
            }
            if (ans[n - 1] <= 0) {
                arraycopy(prev, 0, prevOpt, 0, n)
                rr = mid
            } else {
                ll = mid
            }
        }
        val theAns = IntArray(n)
        var theLen = 0
        run {
            var i = n - 1
            while (i >= 0) {
                theAns[theLen++] = i
                i = prevOpt[i]
            }
        }
        for (i in theLen - 1 downTo 0) {
            out!!.print((theAns[i] + 1).toString() + " ")
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