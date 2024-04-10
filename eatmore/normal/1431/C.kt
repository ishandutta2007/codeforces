import java.lang.Math
import java.io.IOException
import java.util.StringTokenizer
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.lang.Exception

fun solve() {
    val tests = scanInt()
    for (test in 0 until tests) {
        val n = scanInt()
        val k = scanInt()
        val p = IntArray(n)
        for (i in 0 until n) {
            p[i] = scanInt()
        }
        var ans = 0
        var cans = 0
        for (i in 1..n) {
            cans += p[n - i]
            if (i / k == (i - 1) / k) {
                cans -= p[n - i + i / k]
            }
            ans = Math.max(ans, cans)
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