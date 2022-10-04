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
		var (n, m) = readInts()
		var U = mutableListOf<Int> ()
		var V = mutableListOf<Int> ()
		var W = mutableListOf<Int> ()
		val ans = IntArray(n) {0}
		for (i in 0 until m) {
			var (u, v, w) = readInts()
			u--
			v--
			U.add(u)
			V.add(v)
			W.add(w)
			ans[u] = max(ans[u], w)
			ans[v] = max(ans[v], w)
		}
		var ok = 1
		for (i in 0 until m) {
			if (W[i] != min(ans[U[i]], ans[V[i]])) {
				ok = 0
				break
			}
		}
		if (ok == 1) {
			println("YES")
			println(ans.joinToString(" "))
		} else {
			println("NO")
		}
	}
}