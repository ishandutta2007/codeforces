import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun solve(src: String, tgt: String): Boolean {
	var i = 0
	var j = 0
	while (true) {
		// println("$i, $j, ${src.length}, ${tgt.length}")
		if (i == src.length && j == tgt.length) {
			return true
		} else if (i == src.length || j == tgt.length) {
			return false
		}
		if (src[i] == tgt[j]) {
			i++
			j++
		} else if (src[i] == '-' && (i < src.length - 1) && src[i+1] == '-' && tgt[j] == '+') {
			i += 2
			j++
		} else {
			return false
		}
	}
}

fun main(args: Array<String>) {
	val t = readInt()
	repeat(t) {
		val src = readLn()
		val tgt = readLn()
		if (solve(src, tgt)) {
			println("YES")
		} else {
			println("NO")
		}
	}
}