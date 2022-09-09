import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun solve() {
    val n = scanInt()
    val m = scanInt()
    val k = scanInt() - 1
    val ans = IntArray(n)
    Arrays.fill(ans, Int.MAX_VALUE - 1)
    ans[k] = 0
    for (i in 0 until m) {
        val x = scanInt() - 1
        val y = scanInt() - 1
        val ax = ans[x]
        val ay = ans[y]
        ans[x] = Math.min(ax + 1, ay)
        ans[y] = Math.min(ay + 1, ax)
    }
    for (i in 0 until n) {
        out.print((if (ans[i] == Int.MAX_VALUE - 1) -1 else ans[i]).toString() + " ")
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