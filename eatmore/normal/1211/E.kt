import java.lang.Integer.parseInt
import java.lang.Long.parseLong
import java.lang.System.exit
import java.util.Arrays.fill

import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.StringTokenizer

object E {

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
        val p1 = IntArray(n / 2)
        val p2 = IntArray(n / 2)
        fill(p1, -1)
        fill(p2, -1)
        for (i in 0 until n) {
            val cur = scanInt() - 1
            if (cur >= n / 2) {
                continue
            }
            if (p1[cur] == -1) {
                p1[cur] = i
            } else if (p2[cur] == -1) {
                p2[cur] = i
            } else {
                p1[cur] = -2
                p2[cur] = -2
            }
        }
        var l = 0
        var r = n / 2
        for (i in 0 until n / 2) {
            if (p2[i] < 0) {
                r = i
                break
            }
        }
        val idx1 = IntArray(n / 2)
        val idx2 = IntArray(n / 2)
        bs@ while (l < r) {
            val mid = l + r + 1 shr 1
            for (i in 0 until mid) {
                idx1[i] = i
                idx2[i] = i
            }
            sortBy(idx1, mid, p1)
            sortBy(idx2, mid, p2)
            for (i in 0 until mid) {
                if (idx1[i] != idx2[i]) {
                    r = mid - 1
                    continue@bs
                }
            }
            l = mid
        }
        val ans = CharArray(n)
        fill(ans, 'B')
        for (i in 0 until l) {
            ans[p1[i]] = 'R'
            ans[p2[i]] = 'G'
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
    E.main(args)
}