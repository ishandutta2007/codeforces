fun main(args: Array<String>) {
    for (testcase in 0 until readLine()!!.toInt()) {
        var (n, m, x, y) = readLine()!!.split(' ').map { it.toInt() } 
        y = Math.min(2 * x, y)
        val ans = (0 until n).map{ readLine()!!}
            .flatMap { it.split('*') }
            .map {it.length }
            .map{ it / 2 * y + it % 2 * x }.sum()
        println(ans)
    }
}