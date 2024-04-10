fun main(args: Array<String>) {
    for (testcase in 0 until readLine()!!.toInt()) {
        val (n, m, k) = readLine()!!.split(' ').map { it.toInt() }
        val x = n / k
        val ans = if (m <= x) { m } else {
            val rest = (m - x + k - 2) / (k - 1)
            x - rest
        }
        println(ans)
    }
}