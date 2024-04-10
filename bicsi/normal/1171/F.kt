import java.lang.Math.max
import java.lang.Math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

data class Range(val beg: Int, val end: Int, val idx: Int)

fun main(args: Array<String>) {
    val t = readInt()
    for (idx in 1..t) {
        val n = readInt()
        val ranges = ArrayList<Range>()
        for (i in 0..n-1) {
            val (b, e) = readInts()
            ranges.add(Range(b, e, i))
        }
        ranges.sortBy { it.beg }
        val target = IntArray(n) { 1 }

        var until = ranges[0].end
        var cnt = 0
        for (range in ranges) {
            if (range.beg <= until) {
                until = max(until, range.end)
                target[range.idx] = 2
                cnt++
            }
        }

        if (cnt == n) println(-1)
        else println(target.joinToString(separator = " "))
    }
}