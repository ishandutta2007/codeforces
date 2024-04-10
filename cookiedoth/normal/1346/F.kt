import java.util.Scanner
import kotlin.math.*
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readIntArray() = readInts().toIntArray()
private fun readLongs() = readStrings().map { it.toLong() } // list of ints
private fun readLongArray() = readLongs().toLongArray()

var rList = LongArray(0) {0}
var cList = LongArray(0) {0}

fun processArr(arr: LongArray):Long {
	var n = arr.size
	var S:Long = arr.sum()
	var center = -1
	var curSum:Long = 0
	for (i in 0 until n) {
		curSum += arr[i]
		if (2 * curSum >= S) {
			center = i
			break
		}
	}
	var res:Long = 0
	for (i in 0 until n) {
		res += abs(i - center) * arr[i]
	}
	return res
}

fun get():Long {
	return processArr(rList) + processArr(cList)
}

fun main(args: Array<String>) {
	var (n, m, q) = readInts()
	rList = LongArray(n) {0}
	cList = LongArray(m) {0}
	var a = Array(n) {LongArray(m) {0} }
	for (i in 0 until n) {
		a[i] = readLongArray()
	}
	for (i in 0 until n) {
		for (j in 0 until m) {
			rList[i] += a[i][j]
			cList[j] += a[i][j]
		}
	}
	println(get())
	for (i in 0 until q) {
		var (r, c, value) = readInts()
		r--
		c--
		rList[r] -= a[r][c]
		cList[c] -= a[r][c]
		a[r][c] = value.toLong()
		rList[r] += a[r][c]
		cList[c] += a[r][c]
		println(get())
	}
}