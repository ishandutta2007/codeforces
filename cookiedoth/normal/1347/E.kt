import java.util.Scanner
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readIntArray() = readInts().toIntArray()

val D = 10;

fun main(args: Array<String>) {
	var T = readInt()

	while ((T--) > 0) {
		var n = readInt()
		if (n <= 3) {
			println(-1)
			continue
		}
		var ans = mutableListOf<Int> ()
		for (i in (n - 1) - (n - 1) % 2 downTo 0 step 2) {
			ans.add(i)
		}
		ans.add(3)
		ans.add(1)
		for (i in 5..(n - 1) step 2) {
			ans.add(i)
		}
		ans.forEach {
			print(it + 1)
			print(' ')
		}
		println()
	}
}