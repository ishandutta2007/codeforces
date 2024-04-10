import kotlin.math.max

fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }.sorted()
    val b = readLine()!!.split(" ").map { it.toInt() }.sorted()

    val m = readLine()!!.toInt()
    val c = readLine()!!.split(" ").mapIndexed { index, s ->  index to s.toInt()}.sortedBy { it.second }
    val answer = IntArray(m)

    val suffix = IntArray(n + 1)
    suffix[n] = Int.MIN_VALUE
    for (i in n - 1 downTo 0) {
        suffix[i] = max(suffix[i + 1], b[i + 1] - a[i])
    }

    var i = 0
    var prefix = Int.MIN_VALUE
    for ((index, candidate) in c) {
        while (i < n && a[i] <= candidate) {
            prefix = max(prefix, b[i] - a[i])
            ++i
        }
        answer[index] = max(max(prefix, suffix[i]), b[i] - candidate)
    }

    println(answer.joinToString(" "))
}