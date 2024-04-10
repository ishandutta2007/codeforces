import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun solve() {
    val tests = scanInt()
    for (test in 0 until tests) {
        val n = scanInt()
        val a = LongArray(n)
        for (i in 0 until n) {
            a[i] = scanLong()
        }
        Arrays.sort(a)
        var ans: Long = 0
        for (i in 0 until n) {
            ans = Math.max(ans, a[i] * (n - i))
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