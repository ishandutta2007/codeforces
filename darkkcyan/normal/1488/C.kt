import kotlin.math.*

fun main() {
    for (i in 1..readLine()!!.toInt()) {
        var (n, x, y) = readLine()!!.split(' ').map {it.toInt()}
        if (x > y) {
            val t = x
            x = y
            y = t
        }

        var ans = n * 6
        for (mid in x until y) {
            var curAns = 0
            curAns = mid - 1 + min(x - 1, mid - x)
            curAns = max(curAns, n - mid - 1 + min(y - mid - 1, n - y))
            ans = min(ans, curAns)
        }
        println(ans)
    }
}