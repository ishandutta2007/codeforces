import java.io.*
import java.util.*

private fun readWords() = readLine()!!.split(" ")

fun main() {
    if (System.getProperty("ONLINE_JUDGE") == null) {
        System.setIn(FileInputStream(File("test.inp")))
//        System.setOut(PrintStream(File("test.out")))
    }

    val (n, k) = readWords().map(String::toInt)
    val a = readWords().map(String::toLong).sorted()
    val sum = LongArray(n + 1)
    for (i in 0 until n) {
        sum[i + 1] = sum[i] + a[i]
    }

    val inf = (1e8).toLong()

    val dp = Array(n + 1){LongArray(k + 1){-inf} }

    dp[0][0] = 0

    for (i in 1 .. n) {
        dp[i] = dp[i - 1].copyOf()
        for (curUse in 1..k) {
            if (curUse * 2 > i) break;
            val cost = sum[i] + sum[i - curUse * 2] - 2 * sum[i - curUse]
            for (prevUse in 0..k - curUse) {
                dp[i][curUse + prevUse] = Math.max(
                    dp[i][curUse + prevUse],
                    dp[i - 2 * curUse][prevUse] + cost
                )
            }
        }

    }
    println(dp[n][k])
}