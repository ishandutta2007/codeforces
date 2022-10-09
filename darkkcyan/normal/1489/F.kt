import kotlin.math.max

fun main() {
    val (n, m, k) = readLine()!!.split(' ').map { it.toInt() }
    val a = readLine()!!.split(' ').map { it.toInt() }

    fun ok(start: Int): Boolean {
        var boxLeft = m - 1
        var capLeft = k
        for (i in start until n) {
            if (capLeft < a[i]) {
                if (boxLeft == 0) return false
                boxLeft --
                capLeft = k
            }
            capLeft -= a[i]
        }
        return true
    }

    var l = 0
    var r = n
    while (l < r) {
        val mid = (l + r) / 2
        if (ok(mid)) r = mid
        else l = mid + 1
    }
    println(n - l)

}