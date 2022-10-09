fun main(args: Array<String>) {
    val (n, k) = readLine()!!.split(' ').map { it.toInt() }
    if (k == 1) {
        println(n)
        return 
    }
    val mod = 998244353L

    val frac = LongArray(n + 10)
    frac[0] = 1
    for (i in 1 until n + 10) {
        frac[i] = frac[i - 1] * i % mod
    }

    fun mpow(base_: Long, exp_: Long): Long {
        var (base, exp) = base_ to exp_
        var ans = 1L
        while (exp > 0) {
            if ((exp and 1L) == 1L) ans = ans * base % mod
            base = base * base % mod
            exp = exp shr 1
        }
        return ans
    }

    fun choose(from: Int, count: Int): Long = 
        frac[from] * mpow(frac[count], mod - 2) % mod * mpow(frac[from - count], mod - 2) % mod

    var ans = 0L
    for (i in 1 until n) {
        val left = n / i - 1
        if (left < k - 1) continue;
        ans = (ans + choose(left, k - 1)) % mod
    }
    println(ans)
}