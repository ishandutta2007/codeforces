fun main() {
    for (testcase in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map {it.toLong()}.sorted()
        var ans = a[0]
        for (i in 1 until n) {
            ans = ans.coerceAtLeast(a[i] - a[i - 1])
        }
        println(ans)
    }
}