fun main() {
    for (testcase in 1..readLine()!!.toInt()) {
        var (x0, n) = readLine()!!.split(' ').map {it.toLong()}
        val cnt = n % 4
        for (i in n - cnt + 1 .. n) {
            if (x0 % 2.toLong() == 0.toLong()) {
                x0 -= i
            } else {
                x0 += i
            }
        }
        println(x0)
    }
}