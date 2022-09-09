import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun solve() {
    val n = scanInt()
    val m = scanInt()
    val k = scanLong()
    val a = LongArray(n)
    val b = LongArray(m)
    val c = Array(n) { LongArray(m) }
    for (i in 0 until n) {
        a[i] = scanLong()
    }
    for (i in 0 until m) {
        b[i] = scanLong()
    }
    for (i in 0 until n) {
        for (j in 0 until m) {
            c[i][j] = scanLong()
        }
    }
    val thresh = LongArray(n + m)
    val score = LongArray(n + m)
    var cnt = 0
    var pi = 0
    var pj = 0
    while (pi < n || pj < m) {
        var cthresh: Long
        var cscore: Long = 0
        if (pj == m || pi < n && a[pi] < b[pj]) {
            cthresh = a[pi]
            for (i in 0 until pj) {
                cscore = Math.max(cscore, c[pi][i])
            }
            ++pi
        } else {
            cthresh = b[pj]
            for (i in 0 until pi) {
                cscore = Math.max(cscore, c[i][pj])
            }
            ++pj
        }
        if (cnt > 0 && thresh[cnt - 1] == cthresh) {
            --cnt
            cscore = Math.max(cscore, score[cnt])
        }
        if (cnt == 0 || cscore > score[cnt - 1]) {
            thresh[cnt] = cthresh
            score[cnt] = cscore
            ++cnt
        }
    }
    val target = Math.max(a[n - 1], b[m - 1])
    var ans = Long.MAX_VALUE
    for (p in 0 until cnt) {
        var cans: Long = 0
        var cscore: Long = 0
        var cmax: Long = 0
        for (i in 0 until cnt) {
            if (cscore < thresh[i]) {
                val cur = (thresh[i] - cscore + cmax - 1) / cmax
                cans += cur
                cscore += cur * cmax
            }
            cmax = Math.max(cmax, if (i == p) score[i] + k else score[i])
        }
        if (cscore < target) {
            cans += (target - cscore + cmax - 1) / cmax
        }
        ans = Math.min(ans, cans)
    }
    out.print(ans)
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