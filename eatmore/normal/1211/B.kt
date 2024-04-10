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
        var ans: Long = 0
        for (i in 0 until n) {
            val cur = scanInt()
            ans = max(ans, n.toLong() * (cur - 1) + i.toLong() + 1)
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
    B.main(args)
}