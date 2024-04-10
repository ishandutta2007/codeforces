import java.io.*
import java.util.*
import kotlin.math.*

val out = PrintWriter(System.out, false)
val bf = BufferedReader(InputStreamReader(System.`in`))
var stok = StringTokenizer("")
fun read(): String {
    while (!stok.hasMoreTokens()) stok = StringTokenizer(bf.readLine())
    return stok.nextToken()
}

fun main() {
    solve()
    out.flush()
}

// the real main
fun solve() {
    val n = read().toInt()
    val m = read().toInt()
    val a = IntArray(n) { read().toInt() }.map { it % 2 }.count {it == 1}
    val b = IntArray(m) { read().toInt() }.map { it % 2 }.count {it == 1}
    out.println(Math.min(a, m - b) + Math.min(b, n - a))
}