fun main() {
    for (testcase in 0 until readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map(String::toInt)
        var ans = 0
        for (i in 0 until n) {
            val (l, r) = readLine()!!.split(' ').map(String::toInt)
            if (k in l..r) {
                ans = Math.max(ans, r - k + 1)
            }
        }
        println(ans)
    }
}