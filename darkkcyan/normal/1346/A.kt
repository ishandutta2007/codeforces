fun main(args: Array<String>) {
    for (testcase in 1..readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map { it.toLong() }
        val n1 = n / (1 + k + k * k + k * k * k)
        println("$n1 ${n1 * k} ${n1 * k * k} ${n1 * k * k * k}")
    }
}