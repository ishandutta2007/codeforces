import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

object B {
    fun sortBy(a: IntArray, n: Int, v: IntArray) {
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
            while ((j shl 1) + 2 + Int.MIN_VALUE < i + Int.MIN_VALUE) {
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
    fun solve() {
        val tests = scanInt()
        test@ for (test in 0 until tests) {
            val n = scanInt()
            val evs = IntArray(2 * n)
            val idx = IntArray(2 * n)
            var i = 0
            while (i < 2 * n) {
                evs[i] = scanInt()
                evs[i + 1] = scanInt() + 1
                idx[i] = i
                idx[i + 1] = i + 1
                i += 2
            }
            sortBy(idx, 2 * n, evs)
            var cnt = 0
            var prev = -1
            for (i in idx) {
                if (evs[i] != prev) {
                    if (cnt == 1) {
                        out!!.println(prev)
                        continue@test
                    }
                    prev = evs[i]
                }
                if (i and 1 == 0) {
                    ++cnt
                } else {
                    --cnt
                }
            }
            out!!.println(-1)
        }
    }

    @Throws(IOException::class)
    fun scanInt(): Int {
        return scanString().toInt()
    }

    @Throws(IOException::class)
    fun scanLong(): Long {
        return scanString().toLong()
    }

    @Throws(IOException::class)
    fun scanString(): String {
        while (tok == null || !tok!!.hasMoreTokens()) {
            tok = StringTokenizer(`in`!!.readLine())
        }
        return tok!!.nextToken()
    }

    var `in`: BufferedReader? = null
    var out: PrintWriter? = null
    var tok: StringTokenizer? = null
    fun main() {
        try {
            `in` = BufferedReader(InputStreamReader(System.`in`))
            out = PrintWriter(System.out)
            solve()
            `in`!!.close()
            out!!.close()
        } catch (e: Throwable) {
            e.printStackTrace()
            System.exit(1)
        }
    }
}

fun main() {
    B.main()
}