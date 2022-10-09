import kotlin.math.max
import kotlin.math.min

fun main() {
    val maxn = 202020
    val pos = IntArray(maxn)
    var left = 1
    var right = -1

    for (qr in 1 .. readLine()!!.toInt()) {
        val (t, ids) = readLine()!!.split(' ')
        val id = ids.toInt()

        when (t[0]) {
            'L' -> pos[id] = left - 1
            'R' -> pos[id] = right + 1
            '?' -> println(min(pos[id] - left, right - pos[id]))
        }

        left = min(left, pos[id])
        right = max(right, pos[id])
    }
}