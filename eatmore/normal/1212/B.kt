import java.lang.Integer.parseInt
import java.lang.Long.parseLong
import java.lang.Math.max
import java.lang.System.exit

import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.StringTokenizer

object B {

    internal var `in`: BufferedReader? = null
    internal var out: PrintWriter? = null
    internal var tok: StringTokenizer? = null

    @Throws(Exception::class)
    internal fun solve() {
        val n = scanInt()
        val s = scanString()
        val cnts = IntArray(26 * 26)
        var maxcnt = 0
        for (i in 0 until n - 1) {
            maxcnt = max(maxcnt, ++cnts[s[i] - 'A' + (s[i + 1] - 'A') * 26])
        }
        for (i in 0 until 26 * 26) {
            if (cnts[i] == maxcnt) {
                out!!.print("" + (i % 26 + 'A'.toInt()).toChar() + (i / 26 + 'A'.toInt()).toChar())
                break
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
    B.main(args)
}