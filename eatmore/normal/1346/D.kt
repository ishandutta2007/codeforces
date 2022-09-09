import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun solve() {
    val tests = scanInt()
    test@ for (test in 0 until tests) {
        val n = scanInt()
        val m = scanInt()
        val u = IntArray(m)
        val v = IntArray(m)
        val w = IntArray(m)
        for (i in 0 until m) {
            u[i] = scanInt() - 1
            v[i] = scanInt() - 1
            w[i] = scanInt()
        }
        val a = IntArray(n)
        for (i in 0 until m) {
            a[u[i]] = Math.max(a[u[i]], w[i])
            a[v[i]] = Math.max(a[v[i]], w[i])
        }
        for (i in 0 until m) {
            if (w[i] != Math.min(a[u[i]], a[v[i]])) {
                out.println("NO")
                continue@test
            }
        }
        out.println("YES")
        for (i in 0 until n) {
            out.print(a[i].toString() + " ")
        }
        out.println()
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