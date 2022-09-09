import kotlin.Throws
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
        var x = scanInt() - 1
        var y = scanInt() - 1
        var ans = Int.MAX_VALUE
        if (x > y) {
            val t = x
            x = y
            y = t
        }
        for (p in x + 1..y) {
            ans = Math.min(ans, Math.max(p - 1 + Math.min(x, p - x - 1), n - p - 1 + Math.min(y - p, n - y - 1)))
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