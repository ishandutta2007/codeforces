import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	val t = readInt()
	var bad = 0
	var best = 0
	var best2 = 0
	val xs = readInts()
	for (x in xs) {
		if (best > x && best2 > x) {
			bad += 1
		}
		if (x >= best) {
			best2 = best
			best = x
		} else if (x >= best2) {
			best2 = x
		}
	}
	println(bad)
}