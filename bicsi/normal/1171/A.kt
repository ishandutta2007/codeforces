private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    val n = readInt()
    val dp = IntArray(101)
    for (i in 2..100) {
        if (i <= 7) dp[i] = 1
        else dp[i] = dp[i - 6] + 1
    }

    for (itr in 1..n) {
        println(dp[readInt()])
    }
}