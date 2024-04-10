import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    val t = readInt()
    repeat(t) {
		val (a, b) = readInts()
		val c = min(a, b) - 1
		println("${c} ${a - c} ${b - c}")
    }
}