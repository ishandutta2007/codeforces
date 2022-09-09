import java.lang.Integer.parseInt
import java.lang.Long.parseLong
import java.lang.System.exit

import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.StringTokenizer

object C {

    internal var `in`: BufferedReader? = null
    internal var out: PrintWriter? = null
    internal var tok: StringTokenizer? = null

    internal fun sort(a: IntArray, n: Int) {
        if (n == 0) {
            return
        }
        for (i in 1 until n) {
            var j = i
            val ca = a[i]
            do {
                val nj = j - 1 shr 1
                val na = a[nj]
                if (ca <= na) {
                    break
                }
                a[j] = na
                j = nj
            } while (j != 0)
            a[j] = ca
        }
        var ca = a[0]
        for (i in n - 1 downTo 1) {
            var j = 0
            while ((j shl 1) + 2 + Integer.MIN_VALUE < i + Integer.MIN_VALUE) {
                j = j shl 1
                j += if (a[j + 2] > a[j + 1]) 2 else 1
            }
            if ((j shl 1) + 2 == i) {
                j = (j shl 1) + 1
            }
            var na = a[i]
            a[i] = ca
            ca = na
            while (j != 0 && a[j] < ca) {
                j = j - 1 shr 1
            }
            while (j != 0) {
                na = a[j]
                a[j] = ca
                ca = na
                j = j - 1 shr 1
            }
        }
        a[0] = ca
    }

    @Throws(Exception::class)
    internal fun solve() {
        val n = scanInt()
        val k = scanInt()
        val a = IntArray(n)
        for (i in 0 until n) {
            a[i] = scanInt()
        }
        sort(a, n)
        out!!.print(if (k == 0) if (a[0] == 1) -1 else a[0] - 1 else if (k == n || a[k] != a[k - 1]) a[k - 1] else -1)
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
    C.main(args)
}