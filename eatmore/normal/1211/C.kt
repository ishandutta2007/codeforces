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

    internal fun sortBy(a: IntArray, n: Int, v: IntArray) {
        if (n == 0) {
            return
        }
        for (i in 1 until n) {
            var j = i
            val ca = a[i]
            val cv = v[ca]
            do {
                val nj = j - 1 shr 1
                val na = a[nj]
                if (cv <= v[na]) {
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
                j += if (v[a[j + 2]] > v[a[j + 1]]) 2 else 1
            }
            if ((j shl 1) + 2 == i) {
                j = (j shl 1) + 1
            }
            var na = a[i]
            a[i] = ca
            ca = na
            val cv = v[ca]
            while (j != 0 && v[a[j]] < cv) {
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
        var k = scanInt().toLong()
        var ans: Long = 0
        val a = IntArray(n)
        val b = IntArray(n)
        val c = IntArray(n)
        val idx = IntArray(n)
        for (i in 0 until n) {
            a[i] = scanInt()
            b[i] = scanInt()
            c[i] = scanInt()
            idx[i] = i
            k -= a[i].toLong()
            ans += c[i].toLong() * a[i]
            if (k < 0) {
                out!!.print("-1")
                return
            }
        }
        sortBy(idx, n, c)
        for (i in idx) {
            if (k <= b[i] - a[i]) {
                out!!.print(ans + c[i] * k)
                return
            } else {
                k -= (b[i] - a[i]).toLong()
                ans += c[i].toLong() * (b[i] - a[i])
            }
        }
        out!!.print("-1")
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