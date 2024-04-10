import java.io.*
import java.util.*

private val err = System.err
private const val fileName = "test"
private lateinit var out: PrintWriter
private lateinit var bf: BufferedReader
private var stok = StringTokenizer("")
private fun read(): String {
    while (!stok.hasMoreTokens()) stok = StringTokenizer(bf.readLine())
    return stok.nextToken()
}

private fun solve() {
    val mod = 998244353L

    fun Long.sqr() = this * this
    fun Long.mpow(exp: Long): Long =
        if (exp == 0L) 1L
        else if ((exp and 1L) == 1L) this * this.mpow(exp - 1) % mod
        else this.mpow(exp shr 1).sqr() % mod

    fun Long.minv(): Long = this.mpow(mod - 2)

    val inv_100 = (100L).minv()
    val minus1 = mod - 1

    val n = read().toInt()
    var q = read().toInt()
    val a = LongArray(n) { read().toLong() * inv_100 % mod }

    val prod_a = LongArray(n + 1)
    val inv_prod_a = LongArray(n + 1)
    prod_a[0] = 1L
    inv_prod_a[0] = 1L
    for (i in 0 until n) {
        prod_a[i + 1] = prod_a[i] * a[i] % mod
        inv_prod_a[i + 1] = prod_a[i + 1].minv()
    }

    val coef = LongArray(n + 2)
    coef[n + 1] = 0
    coef[n] = 1
    for (i in n - 1 downTo 0 ) {
        coef[i] = (coef[i + 1] * a[i] + 1) % mod
    }

    fun get_prod(from: Int, to: Int): Long = prod_a[to] * inv_prod_a[from] % mod
    fun get_inv_prod(from: Int, to: Int): Long = inv_prod_a[to] * prod_a[from] % mod
//    fun get_coef(from: Int, to: Int): Long =
//        (coef[from] + mod - (coef[to] + mod - 1) * get_prod(from, to) % mod) % mod
//
//    fun recalculate(cur_pos: Int, next_pos: Int): Long {
//        val prod = get_prod(cur_pos, next_pos)
//        val co = get_coef(cur_pos, next_pos)
//        return (co * prod.minv() + mod - 1) % mod
//    }

    fun recalculate(cur_pos: Int, next_pos: Int): Long {
        val prod = get_prod(cur_pos, next_pos)
        val co = coef[cur_pos] + mod - (coef[next_pos] + minus1) * prod % mod
        return (co * get_inv_prod(cur_pos, next_pos) + minus1) % mod
    }

    val dp = TreeMap<Int, Long>()
    dp[0] = recalculate(0, n)
    dp[n] = 1

    var cur_ans = dp[0]!!

    while (q-- > 0) {
        val u = read().toInt() - 1
        val lower = dp.floorKey(u - 1)
        val upper = dp.ceilingKey(u + 1)
        if (u in dp) {
            cur_ans += mod - dp[u]!! - dp[lower]!!
            dp.remove(u)
            dp[lower] = recalculate(lower, upper)
            cur_ans += dp[lower]!!
        } else {
            cur_ans -= dp[lower]!!
            dp[u] = recalculate(u, upper)
            dp[lower] = recalculate(lower, u)
            cur_ans += dp[u]!! + dp[lower]!!
        }
        cur_ans %= mod
        if (cur_ans < 0) cur_ans += mod

        out.printf("%d\n", cur_ans)
    }
}

fun main() {
    if (System.getProperty("ONLINE_JUDGE") == null) {
        assert(fileName != "")
        System.setIn(FileInputStream(File("$fileName.inp")))
        System.setOut(PrintStream(File("$fileName.out")))
    }

    out = PrintWriter(System.out!!, false)
    bf = BufferedReader(InputStreamReader(System.`in`))

    solve()
    out.flush()
}