fun main() {
    val ntest = readLine()!!.toInt()
    for (testcase in 1..ntest) {
        val n = readLine()!!.toInt()
        val min_candy = 1
        val max_candy = (n - 1) / 2
        if (min_candy > max_candy) {
            println(0)
        } else {
            println(max_candy - min_candy + 1)
        }
    }
}