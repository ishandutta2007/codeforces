fun main() {
    val q = readLine()!!.toInt()
    for (qr in 1..q) {
        val n = readLine()!!.toInt()
        val sum = readLine()!!.trim().split(" ").map(String::toLong).sum()
        println((sum + n - 1) / n)
    }
}