import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun gcd(a: Int, b: Int): Int {
    return if (b == 0) a else gcd(b, a % b)
}

fun solve() {
    val k = scanInt()
    val n = scanInt()
    val p = IntArray(k)
    for (i in 0 until k) {
        p[i] = scanInt()
    }
    val x = IntArray(n)
    for (i in 0 until n) {
        x[i] = scanInt()
    }
    if (n == 2) {
        out.println("YES")
        out.println(x[0].toString() + " " + p[0])
        out.println(x[1].toString() + " " + p[0])
        return
    }
    for (pp in 0..2) {
        val x1 = x[if (pp == 0) 1 else 0]
        val x2 = x[if (pp == 2) 1 else 2]
        for (d in p) {
            if ((x2 - x1) % d != 0) {
                continue
            }
            var first = 0
            var gcd = 0
            for (v in x) {
                if ((v - x1) % d != 0) {
                    if (first == 0) {
                        first = v
                    } else {
                        gcd = gcd(gcd, v - first)
                    }
                }
            }
            for (d2 in p) {
                if (gcd % d2 == 0) {
                    out.println("YES")
                    out.println(((x1 - 1) % d + 1).toString() + " " + d)
                    out.println(Math.max(first, 1).toString() + " " + d2)
                    return
                }
            }
        }
    }
    out.print("NO")
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