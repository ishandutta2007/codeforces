fun main(@Suppress("UNUSED_PARAMETER") args: Array<String>) {
    val maxn = 1e6.toInt() + 10
    val (_, a, b, k) = readLine()!!.split(' ').map {it.toInt()}
    val cnt = IntArray(maxn)
    readLine()!!.split(' ').map {it.toInt()}.forEach { x -> cnt[x] ++ }
    
    var ans = 0
    for (i in 1 until maxn) {
        if (i % k == 0) continue
        var dp = IntArray(cnt[i] + 1) { 0 }
        var cur = i
        while (cur * k < maxn) {
            cur *= k
            var nxt_dp = IntArray(cnt[cur] + 1) { 0 }
            
            for (c in 0..cnt[cur]) {
                val res = cnt[cur] - c
                val cnt_team = c / b
                val cnt_below = cnt_team * a
                nxt_dp[res] = if (cnt_below < dp.size) dp[cnt_below] + cnt_team else 0
            }
            dp = nxt_dp
            for (f in dp.size - 2 downTo 0) {
                dp[f] = dp[f].coerceAtLeast(dp[f + 1])
            }
            // println("cur = ${cur}, dp = ${dp.joinToString(", ")}")
        }
        ans += dp[0]
    }
    println(ans)
}