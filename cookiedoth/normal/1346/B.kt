import java.util.Scanner
import kotlin.math.*
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readIntArray() = readInts().toIntArray()

fun main(args: Array<String>) {
	var T = readInt()

	while ((T--) > 0) {
		var (n, k1, k2) = readInts()
		var arr = readLn()
		var ans = 0
		var last = 0
		for (i in 0 until n) {
			if (arr[i] == '0') {
				last = 0
			} else {
				last = min(k1, k2 - last)
				ans += last
			}
		}
		println(ans)
	}
}