fun main() {
    val dp = Array(100) { 0 }
    dp[1] = 0
    for (i in 2..50) {
        val sg = mutableSetOf<Int>()
        for (j in 1 until i) {
            sg.add(dp[j] xor dp[i - j])
        }
        dp[i] = (0..50).first { !sg.contains(it) }
    }
    val t = readLine()!!.toInt()
    repeat(t) {
        readLine()!!.toInt()
        var sg = 0
        readLine()!!.split(" ").forEach {
            sg = sg xor dp[it.toInt()]
        }
        println(if (sg == 0) "maomao90" else "errorgorn")
    }
}