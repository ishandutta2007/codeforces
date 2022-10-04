import java.util.Scanner
import kotlin.math.*
import kotlin.random.*
import kotlin.system.exitProcess
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readIntArray() = readInts().toIntArray()
private fun readLongs() = readStrings().map { it.toLong() } // list of ints
private fun readLongArray() = readLongs().toLongArray()

fun gcd(a: Int, b: Int): Int {
    if (b == 0) return a
    return gcd(b, a % b)
}

fun main(args: Array<String>) {
	var (k, n) = readInts()
	var p = readInts()
	var x = readInts()
	if (n == 2) {
		println("YES")
		println(x[0].toString() + " " + p[0].toString())
		println(x[1].toString() + " " + p[0].toString())
		exitProcess(0)
	}
	for (it in 0 until 50) {
		var pi = Random.nextInt(n)
		var pj = Random.nextInt(n)
		if (pi == pj) {
			continue
		}
		if (pi > pj) {
			pi = pj.also { pj = pi }
		}
		var D = x[pj] - x[pi]
		var usedD = mutableListOf<Int> ();
		for (curD in p) {
			if (D % curD != 0) {
				continue
			}
			var ok = true
			for (lowerD in usedD) {
				if (curD % lowerD == 0) {
					ok = false
					break
				}
			}
			if (!ok) {
				continue
			}
			usedD.add(curD)
			var lowestUs = -1
			var lowestThem = -1
			var g = 0
			var lastThem = -1
			for (i in 0 until n) {
				if (x[i] % curD == x[pi] % curD) {
					if (lowestUs == -1) {
						lowestUs = x[i]
					}
				} else {
					if (lowestThem == -1) {
						lowestThem = x[i]
						lastThem = x[i]
					} else {
						g = gcd(g, x[i] - lastThem)
						lastThem = x[i]
					}
				}
			}
			if (lowestThem == -1) {
				println("YES")
				println(lowestUs.toString() + " " + curD.toString())
				println("1 " + p[0].toString())
				exitProcess(0)
			}
			for (step in p) {
				if (g % step == 0) {
					println("YES")
					println(lowestUs.toString() + " " + curD.toString())
					println(lowestThem.toString() + " " + step.toString())
					exitProcess(0)
				}
			}
		}
	}
	println("NO")
}