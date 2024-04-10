import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun solve() {
    val n = scanInt()
    val m = scanInt()
    val q = scanInt()
    val a = Array(n) { IntArray(m) }
    val rows = LongArray(n)
    val cols = LongArray(m)
    var total: Long = 0
    for (i in 0 until n) {
        for (j in 0 until m) {
            a[i][j] = scanInt()
            rows[i] = rows[i] + a[i][j]
            cols[j] = cols[j] + a[i][j]
            total += a[i][j]
        }
    }
    var i = 0
    while (true) {
        var sum: Long = 0
        var ans: Long = 0
        var p: Int
        p = 0
        while (2 * sum < total) {
            sum += rows[p]
            p++
        }
        --p
        for (j in 0 until n) {
            ans += rows[j] * Math.abs(j - p)
        }
        sum = 0
        p = 0
        while (2 * sum < total) {
            sum += cols[p]
            p++
        }
        --p
        for (j in 0 until m) {
            ans += cols[j] * Math.abs(j - p)
        }
        out.print("$ans ")
        if (i == q) {
            break
        }
        val x = scanInt() - 1
        val y = scanInt() - 1
        val z = scanInt() - a[x][y]
        a[x][y] += z
        rows[x] = rows[x] + z
        cols[y] = cols[y] + z
        total += z.toLong()
        i++
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