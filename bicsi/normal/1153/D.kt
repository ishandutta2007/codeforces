import java.lang.Math.max
import java.lang.Math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints


fun main(args: Array<String>) {
    val n = readInt()
    val type = readInts().toIntArray()
    val parent = readInts().map{ it - 1 }.toIntArray()
    val dp = IntArray(n) { -1 }

    var leaves = 0
    for (node in n - 1 downTo 1) {
        if (dp[node] == -1) {
            dp[node] = 1
            leaves += 1
        }
        val par = parent[node - 1]
        if (dp[par] == -1) dp[par] = dp[node]
        else {
            if (type[par] == 0) dp[par] += dp[node]
            else dp[par] = min(dp[par], dp[node])
        }
    }
    println(leaves - dp[0] + 1)
}