fun main(args: Array<String>) {
    for (testcase in 1..readLine()!!.toInt()) {
        val (n, k1, k2) = readLine()!!.split(' ').map{ it.toInt() }
        val u = k1
        val v = Math.min(k2 - k1, k1)
        val ans = readLine()!!.split('0')
            .map {it.length}
            .map { (it + 1) / 2 * u + it / 2 * v }
            .sum()
        println(ans)
    }
}