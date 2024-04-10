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
        val k = scanInt()
        val s = scanString()
        var outer = 0
        var i = 0
        var j = 0
        while (i < n) {
            if (j == 0) {
                ++outer
            }
            if (s[i] == '(') {
                ++j
            } else {
                --j
            }
            i++
        }
        out.println(Math.min(n / 2, outer + k))
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