import java.lang.Integer.parseInt
import java.lang.Long.parseLong
import java.lang.Math.abs
import java.lang.Math.min
import java.lang.System.exit

import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.StringTokenizer

object F {

    internal val ones = LongArray(17)
    internal val total = LongArray(17)

    internal var `in`: BufferedReader? = null
    internal var out: PrintWriter? = null
    internal var tok: StringTokenizer? = null

    init {
        for (i in 1 until ones.size) {
            ones[i] = 10 * ones[i - 1] + 1
            total[i] = total[i - 1] + 6 * ones[i]
        }
    }

    internal fun solve(n: Long, i: Int): Int {
        if (n > total[i] || n < -total[i]) {
            return -1
        }
        if (i == 0) {
            return 0
        }
        var ans = Integer.MAX_VALUE
        for (j in -6..6) {
            val cans = solve(n + j * ones[i], i - 1)
            if (cans >= 0) {
                ans = min(ans, cans + abs(j) * i)
            }
        }
        return if (ans == Integer.MAX_VALUE) -1 else ans
    }

    @Throws(Exception::class)
    internal fun solve() {
        val n = scanLong()
        out!!.print(solve(n, 16))
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