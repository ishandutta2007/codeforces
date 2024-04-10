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
		var arr = readInts()
		var ptrL = 0
		var ptrR = n - 1
		var roundCnt = 0
		var sumA = 0
		var sumB = 0
		var lastSum = 0
		while (ptrL <= ptrR) {
			var curSum = 0
			while (ptrL <= ptrR && curSum <= lastSum) {
				curSum += arr[ptrL++]
			}
			roundCnt++
			sumA += curSum
			lastSum = curSum
			if (ptrL <= ptrR) {
				curSum = 0
				while (ptrL <= ptrR && curSum <= lastSum) {
					curSum += arr[ptrR--]
				}
				roundCnt++
				sumB += curSum
				lastSum = curSum
			}
		}
		println(roundCnt.toString() + ' ' + sumA.toString() + ' ' + sumB.toString())
	}
}