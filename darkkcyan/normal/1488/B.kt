import kotlin.math.*

fun main() {
    for (testcase in 1.. readLine()!!.toInt()) {
        var (n, k) = readLine()!!.split(' ').map {it.toInt()}
        val s = readLine()!!.trim()

        var sum = 0
        var ans = 0
        var cnt = 0
        for ((i, ch) in s.withIndex()) {
            if (ch == '(') {
                ++sum
            } else {
                --sum
                if (sum > 0) continue
                ++cnt
            }
        }
        println(cnt + min(n / 2 - cnt, k))
    }
}