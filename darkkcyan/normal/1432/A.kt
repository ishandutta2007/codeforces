fun main() {
    val ntest = readLine()!!.trim().toInt()
    for (testcase in 0 until ntest) {
        val (a, b) = readLine()!!.trim().split(" ").map(String::toInt)
        println(a + b)
    }
}