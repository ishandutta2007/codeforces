import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

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

fun solve() {
    val n = scanInt()
    val m = scanInt()
    val q = scanInt()
    val mat = arrayOfNulls<CharArray>(n)
    for (i in 0 until n) {
        mat[i] = scanString().toCharArray()
    }
    val sufOrder = Array(m) { IntArray(n) }
    val sufOrd = Array(m) { IntArray(n) }
    for (i in m - 1 downTo 0) {
        for (j in 0 until n) {
            sufOrder[i][j] = j
            sufOrd[i][j] = mat[j]!![i].toInt() * n + if (i == m - 1) 0 else sufOrd[i + 1][j]
        }
        sortBy(sufOrder[i], n, sufOrd[i])
        for (j in 0 until n) {
            sufOrd[i][sufOrder[i][j]] = j
        }
    }
    q@ for (qq in 0 until q) {
        val s = scanString()
        var p = 0
        var l = 0
        var r = n
        var ans = 0
        var i = 0
        while (i < m) {
            var ll = l
            var rr = r
            while (ll < rr) {
                val mm = ll + rr shr 1
                if (mat[sufOrder[p][mm]]!![i] < s[i]) {
                    ll = mm + 1
                } else {
                    rr = mm
                }
            }
            var ll2 = ll
            var rr2 = r
            while (ll2 < rr2) {
                val mm2 = ll2 + rr2 shr 1
                if (mat[sufOrder[p][mm2]]!![i] > s[i]) {
                    rr2 = mm2
                } else {
                    ll2 = mm2 + 1
                }
            }
            if (ll == ll2) {
                if (p == i) {
                    out.println(-1)
                    continue@q
                }
                p = i
                l = 0
                r = n
                ++ans
                continue
            }
            ++i
            l = ll
            r = ll2
        }
        out.println(ans)
    }
}

fun scanInt(): Int {
    return scanString().toInt()
}

fun scanLong(): Long {
    return scanString().toLong()
}

fun scanString(): String {
    var t = tok
    while (t == null || !t.hasMoreTokens()) {
        t = StringTokenizer(inp.readLine())
        tok = t
    }
    return t.nextToken()
}

val inp = BufferedReader(InputStreamReader(System.`in`))
val out = PrintWriter(System.out)
var tok: StringTokenizer? = null
fun main() {
    solve()
    inp.close()
    out.close()
}