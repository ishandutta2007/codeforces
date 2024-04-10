fun main() {
    var (n, m) = readLine()!!.split(' ').map{it.toInt()}
    var rest = MutableList<Pair<Int, Int>>(0) {0 to 0}
    val ans = IntArray(n) {-1}
    for (i in 0 until n) {
        val (k, t) = readLine()!!.split(' ').map{it.toInt()}
        if (t == 1) {
            ans[i] = m - k + 1
            m -= k
        } else {
            rest.add(k to i)
        }
    }
    if (m < 0) {
        println("-1")
        return 
    }
    
    val even_side = m / 2
    val odd_side = m - even_side
    // println("odd_side = $odd_side, even_side = $even_side") 
    val dp = Array(rest.size + 1) { IntArray(odd_side + 1) { -1} }
    dp[0][odd_side] = 0
    var sum_rest = 0
    for ((i, value) in rest.withIndex()) {
        val (k, _) = value
        for (x in 0 .. odd_side) {
            if (dp[i][x] == -1) continue
            if (x >= k) {
                dp[i + 1][x - k] = 0
            }
            val used_odd = odd_side - x
            if (even_side - (sum_rest - used_odd) >= k) {
                dp[i + 1][x] = 1
            }
        }
        // println("$i, dp = ${dp[i + 1].joinToString(", ")}") 
        sum_rest += k
    }
    
    var trace = 0
    while (trace <= odd_side && dp[rest.size][trace] == -1) ++trace
    if (trace > odd_side) {
        println("-1")
        return 
    }
    
    var even_pos = 2
    var odd_pos = 1
    for (i in rest.size downTo 1) {
        val (k, id) = rest[i - 1]
        if (dp[i][trace] == 0) {
            ans[id] = odd_pos
            trace += k
            odd_pos += 2 * k
        } else {
            ans[id] = even_pos
            even_pos += 2 * k
        }
    }
    println("${ans.joinToString(" ")}")
}