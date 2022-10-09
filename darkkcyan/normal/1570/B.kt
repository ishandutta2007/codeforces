fun main() {
    var a1 = readLine()!!.toInt()
    var a2 = readLine()!!.toInt()
    var k1 = readLine()!!.toInt()
    var k2 = readLine()!!.toInt()
    
    if (k1 > k2) {
        val ta = a1
        a1 = a2
        a2 = ta
        
        val tk = k1
        k1 = k2
        k2 = tk
    }
    
    val n = readLine()!!.toInt()
    
    val mx_not_pick = a1 * (k1 - 1) + a2 * (k2 - 1)
    val min_ans = Math.max(0, n - mx_not_pick)
    
    val pick1 = Math.min(n / k1, a1)
    val rest = n - pick1 * k1
    val pick2 = Math.min(rest / k2, a2)
    
    val max_ans = pick1 + pick2
    
    println("${min_ans} ${max_ans}")
}