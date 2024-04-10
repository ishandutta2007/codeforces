import java.lang.Math.max
import java.lang.Math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints


fun main(args: Array<String>) {
    val t = readInt()
    for (tt in 1..t) {
        val (x, y) = readInts()
        if (x < y) {
            println(intArrayOf(x - 1, 1, y - x + 1).joinToString(separator = " "))
        } else {
            println(intArrayOf(y - 1, 1, x - y + 1).joinToString(separator = " "))
        }
    }
}