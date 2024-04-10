import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun majorityCount(xs: List<Int>): Pair<Int, Int>? {
	var cur = -1
	var majorness = 0
	for (x in xs) {
		if (majorness == 0) {
			cur = x
			majorness = 1
		} else if (cur == x) {
			majorness++
		} else {
			majorness--
		}
	}
	var count = 0
	for (x in xs) {
		if (x == cur) {
			count += 1
		}
	}
	if (2*count > xs.size) {
		return Pair(cur, count)
	}
	return null
}

fun boringSolve(xs: List<Int>): List<Int> {
	val ret: ArrayList<Int> = ArrayList()
	if (xs.size % 2 == 1) {
		ret.add(xs[xs.size - 1])
	}
	val h = xs.size / 2
	for (i in (h - 1) downTo 0) {
		ret.add(xs[i])
		ret.add(xs[i + h])
	}
	return ret
}

fun solve(xs: List<Int>): List<Int> {
	val mc = majorityCount(xs)
	if (mc == null) {
		// the boring strategy works
		return boringSolve(xs)
	} else {
		val (majority, count) = mc
		val halfSol = xs.size - count
		// we can get 2*(xs.size - count) with a boring solution
		// the question is simply whether we can get 2*(xs.size - count) + 1
		if (majority == xs.first()) {
			val ret: ArrayList<Int> = ArrayList()
			for (i in (xs.size - halfSol)..(xs.size - 1)) {
				ret.add(majority)
				ret.add(xs[i])
			}
			ret.add(majority)
			return ret
		} else if (majority == xs.last()) {
			val ret: ArrayList<Int> = ArrayList()
			for (i in 0..(halfSol - 1)) {
				ret.add(majority)
				ret.add(xs[i])
			}
			ret.add(majority)
			return ret
		} else {
			var seenMajority = 0
			val pruned: ArrayList<Int> = ArrayList()
			for (x in xs) {
				if (x == majority) {
					if (seenMajority < halfSol) {
						pruned.add(x)
						seenMajority++
					}
				} else {
					pruned.add(x)
				}
			}
			return boringSolve(pruned)
		}
	}
}

fun main(args: Array<String>) {
	val t = readInt()
	repeat(t) {
		val n = readInt()
		val xs = ArrayList(readInts())
		xs.sort()
		val sol = solve(xs)
		println(sol.size)
		println(sol.joinToString(" "))
	}
}