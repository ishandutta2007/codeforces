import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	val (nDoors, nCompartments) = readInts()
	val widths = readInts()
	val nQueries = readInt()
	val cumsum: ArrayList<Int> = ArrayList()
	cumsum.add(0)
	for (w in widths) {
		cumsum.add(cumsum.last() + w)
	}
	repeat (nQueries) {
		val indices = readInts().drop(1)
		var i = 0 // how many doors we've fit so far
		var lastX = 0
		for (x in indices) {
			// figure out how many doors we can fit
			var lo = i // works (no doors)
			var hi = nDoors + 1 // impossible
			val howMuchRoom = x - lastX - 1
			while (hi - lo > 1) {
				val mid = (hi + lo) / 2
				if (cumsum[mid] - cumsum[i] <= howMuchRoom) {
					lo = mid
				} else {
					hi = mid
				}
			}

			i = lo
			lastX = x
		}

		// lol
		val x = nCompartments + 1
			var lo = i // works (no doors)
			var hi = nDoors + 1 // impossible
			val howMuchRoom = x - lastX - 1
			while (hi - lo > 1) {
				val mid = (hi + lo) / 2
				if (cumsum[mid] - cumsum[i] <= howMuchRoom) {
					lo = mid
				} else {
					hi = mid
				}
			}

			i = lo
			lastX = x
		if (i == nDoors) {
			println("YES")
		} else {
			println("NO")
		}
	}
}