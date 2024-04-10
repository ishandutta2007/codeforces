fun main(args: Array<String>) {
    for (testcase in 1..readLine()!!.toInt()) {
        val (n, k, x, y) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toLong() }.sortedBy {-it}
        var s = a.sum()
        var ans = x.toLong() * n
        for (i in 0 until n) {
            if ((s + n - 1) / n <= k.toLong()) {
                ans = Math.min(ans, x.toLong() * i + y)
            }
            if (a[i] <= k) {
                ans = Math.min(ans, x.toLong() * i)
            }
            s -= a[i]
        }
        println(ans)

    }
}