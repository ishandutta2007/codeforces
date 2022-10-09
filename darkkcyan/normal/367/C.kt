import java.io.*
import java.util.*

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
    val n = read().toLong()
    val m = read().toInt()
    val a = LongArray(m) {
        read()
        read().toLong()
    }.sorted().reversed()
    var l = 0
    var r = m + 1
    fun nLength(x: Long) = x * (x - 1) / 2 + 1 + (if (x % 2 == 0L) x / 2 - 1 else 0)
    while (r - l > 1) {
        val mid = (l + r) / 2
        if (nLength(mid.toLong()) > n) r = mid
        else l = mid
    }
    val ans = a.subList(0, Math.min(l, m)).reduce(Long::plus)
    out.println(ans)
}