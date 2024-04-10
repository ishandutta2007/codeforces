import java.util.Scanner
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readIntArray() = readInts().toIntArray()

fun main(args: Array<String>) {
	var T = readInt()

	while ((T--) > 0) {
		var (n, k) = readInts()
		var p = n / (1 + k + k * k + k * k * k)
		println(p.toString() + " " + (p * k).toString() + " " + (p * k * k).toString() + " " + (p * k * k * k).toString())
	}
}