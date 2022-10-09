import kotlin.math.*

fun main() {
    for (testcase in 1..readLine()!!.toInt()) {
        var (n, a, b) = readLine()!!.split(' ').map { it.toLong() }
        var ans = 0L
        if (n % 2 == 1L) {
            ans += a
            --n
        }
        b = min(2 * a, b)
        ans += n / 2 * b
        println(ans)
    }
}