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
		var (n, k, x, y) = readInts()
		var a = readInts()
		a = a.sorted()
		var biggerK = 0
		for (i in 0 until n) {
			if (a[i] > k) {
				biggerK++
			}
		}
		var remEl = n
		var sum:Long = 0
		for (i in 0 until n) {
			sum += a[i]
			if (sum > n.toLong() * k.toLong()) {
				remEl = i
				break
			}
		}
		var ans = min(biggerK * x, y + (n - remEl) * x)
		println(ans)
	}
}