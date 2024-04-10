import java.lang.Math.max
import java.lang.Math.min
import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints


fun main(args: Array<String>) {
    val (n, m) = readInts()
    val widths = intArrayOf(0) + readInts().toIntArray()
    for (i in 1..widths.size - 1)
        widths[i] += widths[i - 1]

    val q = readInt()
    for (qq in 1..q) {
        val positions = intArrayOf(0) + readInts().drop(1).toIntArray() + intArrayOf(m + 1)
        // println(positions.joinToString(separator = " "))

        var at = 0
        for (i in 1..positions.size - 1) {
            val space = positions[i] - positions[i - 1] - 1
            var new_at = at
            var step = 1.shl(20)
            while (step > 0) {
                if (new_at + step < widths.size && widths[new_at + step] - widths[at] <= space) {
                    new_at += step
                }
                step /= 2
            }
            at = new_at
        }
        if (at == widths.size - 1) {
            println("YES")
        } else {
            println("NO")
        }
    }
}