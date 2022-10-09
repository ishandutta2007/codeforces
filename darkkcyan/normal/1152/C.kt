import java.io.*
import java.util.*
import kotlin.math.abs
import kotlin.math.ceil
import kotlin.math.min
import kotlin.math.sqrt


fun main() {
    val out = PrintWriter(System.out, false)
    val bf = BufferedReader(InputStreamReader(System.`in`))
    var stok = StringTokenizer("")
    fun read(): String {
        while (!stok.hasMoreTokens()) stok = StringTokenizer(bf.readLine())
        return stok.nextToken()
    }
    fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a % b)
    fun lcm(a: Long, b: Long): Long = a / gcd(a, b) * b
    fun solve() {
        val a = read().toLong()
        val b = read().toLong()
        fun mceil(u: Long, v: Long) = ((u + v - 1) / v) * v
        var ans = lcm(a, b) to 0L
        val g = abs(a - b)
        for (i in 1..ceil(sqrt(g.toDouble())).toInt()) {
            if (abs(a - b) % i != 0L) continue
            val u = lcm(mceil(a, i.toLong()), mceil(b, i.toLong())) to mceil(a, i.toLong()) - a
            val v = lcm(mceil(a, g / i), mceil(b, g / i)) to mceil(a, g / i) - a
            ans = minOf(ans, u, v, compareBy({it.first}, {it.second}))
        }
        out.println(ans.second)
    }

    solve()
    out.flush()
}