import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun solve() {
    val n = scanInt()
    val k = scanInt()
    val x = scanInt()
    val a = IntArray(n)
    var sa: Long = 0
    for (i in 0 until n) {
        a[i] = scanInt()
        sa += a[i]
    }
    var l: Long = 0
    var r = sa
    bs@ while (l < r) {
        val m = l + r shr 1
        val q = PriorityQueue<Int>()
        var p = 0
        var c = 0
        var have = k
        var sum: Long = 0
        while (p < n) {
            if (c == x) {
                c = 0
                sum = 0
                q.clear()
            }
            ++c
            sum += a[p]
            q.add(-a[p])
            ++p
            if (sum > m) {
                if (have == 0) {
                    l = m + 1
                    continue@bs
                }
                --have
                --c
                sum += q.remove()
            }
        }
        r = m
    }
    out.print(l)
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