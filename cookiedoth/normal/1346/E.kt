import java.util.Scanner
import kotlin.math.*
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readIntArray() = readInts().toIntArray()

fun main(args: Array<String>) {
	val Inf = 1000000000
	var (n, m, k) = readInts()
	k--
	val ans = IntArray(n) {Inf}
	ans[k] = 0
	for (i in 0 until m) {
		var (x, y) = readInts()
		x--
		y--
		var px = ans[x]
		var py = ans[y]
		ans[x] = min(py, px + 1)
		ans[y] = min(px, py + 1)
	}
	for (i in 0 until n) {
		if (ans[i] == Inf) {
			ans[i] = -1
		}
	}
	println(ans.joinToString(" "))
}