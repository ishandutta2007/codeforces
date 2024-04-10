import java.io.*
import java.util.*
import java.lang.System.err

private const val localFileName = "test"
private lateinit var out: PrintWriter
private lateinit var bf: BufferedReader
private var stok = StringTokenizer("")
private fun read(): String {
    while (!stok.hasMoreTokens()) stok = StringTokenizer(bf.readLine())
    return stok.nextToken()
}

private fun solve() {
    val mod = 998244353L
    val maxn = 201010
    fun Long.sqr() = this * this
    fun Long.mpow(exp: Long): Long = when {
        exp == 0L -> 1L
        (exp and 1L) == 1L -> this * this.mpow(exp - 1) % mod
        else -> this.mpow(exp / 2).sqr() % mod
    }

    val inv_2 = 2L.mpow(mod - 2)

    val fac = LongArray(maxn)
    val inv_fac = LongArray(maxn)
    fac[0] = 1
    for (i in 1 until maxn) fac[i] = (fac[i - 1] * i) % mod
    for (i in 0 until maxn) inv_fac[i] = fac[i].mpow(mod - 2)

    val pow2 = LongArray(maxn)
    pow2[0] = 1
    for (i in 1 until maxn) pow2[i] = pow2[i - 1] * 2L % mod

    fun comb(n: Int, k: Int) = fac[n] * inv_fac[k] % mod * inv_fac[n - k] % mod

    val n = read().toInt()
    val k = read().toLong()
    if (k == 1L) {
        out.println(0)
        return
    }

    val a = MutableList(n) { read().toInt() }
    var new_len = 1
    for (i in 1 until a.size) {
        if (a[i] == a[i - 1]) continue
        a[new_len++] = a[i]
    }
    if (a[0] == a[new_len - 1]) --new_len
    while (a.size != new_len) a.removeAt(a.lastIndex)

    var ans = 0L

    for (cnt0 in 0 .. a.size) {
        var cur_ans = pow2[a.size - cnt0]
        if ((a.size - cnt0) % 2 == 0)
            cur_ans = (cur_ans + mod - comb(a.size - cnt0, (a.size - cnt0) / 2)) % mod
        cur_ans = (cur_ans * inv_2) % mod
        cur_ans = cur_ans * comb(a.size, cnt0) % mod * (k - 2).mpow(cnt0.toLong()) % mod
        ans = (ans + cur_ans) % mod
    }
    ans = ans * k.mpow((n - a.size).toLong()) % mod
    out.println(ans)
}

fun main() {
    if (System.getProperty("ONLINE_JUDGE") == null) {
        assert(localFileName != "")
        System.setIn(FileInputStream(File("$localFileName.inp")))
        System.setOut(PrintStream(File("$localFileName.out")))
    }

    out = PrintWriter(System.out!!, false)
    bf = BufferedReader(InputStreamReader(System.`in`))

    solve()
    out.flush()
}