import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun solve() {
    val n = scanInt()
    val k = scanInt()
    val a = IntArray(n)
    for (i in 0 until n) {
        a[i] = scanInt()
    }
    Arrays.sort(a)
    val sums = LongArray(n + 1)
    for (i in 0 until n) {
        sums[i + 1] = sums[i] + a[i]
    }
    val dyn = Array(n + 1) { LongArray(k + 1) }
    for (i in 0 until n) {
        for (j in 0 until k) {
            val cur = dyn[i][j] + sums[i]
            var c = 1
            val l = Math.min((n - i) / 2, k - j)
            while (c <= l) {
                dyn[i + 2 * c][j + c] = Math.max(dyn[i + 2 * c][j + c], cur + sums[i + 2 * c] - 2 * sums[i + c])
                c++
            }
            dyn[i + 1][j] = Math.max(dyn[i + 1][j], dyn[i][j])
        }
        dyn[i + 1][k] = Math.max(dyn[i + 1][k], dyn[i][k])
    }
    out.print(dyn[n][k])
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