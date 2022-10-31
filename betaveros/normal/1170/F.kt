import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	val (nWheels, nSlots, increaseability) = readInts()
	val xs = ArrayList(readInts())
	xs.sort()

	val cumsum: ArrayList<Long> = ArrayList()
	cumsum.add(0)
	for (x in xs) {
		cumsum.add(cumsum.last() + x)
	}

	val OO = 1000000000000000000L
	val evaluate = fun(lob: Int, hib: Int, goal: Int): Long {
		// first, find the slice point
		assert(xs[lob] <= goal)
		assert(goal <= xs[hib - 1])
		var lo = lob
		var hi = hib
		while (hi - lo > 1) {
			var mid = (hi + lo) / 2
			if (xs[mid] <= goal) {
				lo = mid
			} else {
				hi = mid
			}
		}
		var slicePoint = hi
		var increaseNeeded = (goal.toLong()) * ((slicePoint - lob).toLong()) - (cumsum[slicePoint] - cumsum[lob])
		var decreaseNeeded = (cumsum[hib] - cumsum[slicePoint]) - (goal.toLong()) * ((hib - slicePoint).toLong())
		// println("$lob $hib $goal -> $slicePoint: $increaseNeeded $decreaseNeeded")
		if (increaseNeeded > increaseability) {
			return OO
		} else {
			return increaseNeeded + decreaseNeeded
		}
	}

	var bestCost = OO
	for (i in 0..nWheels - nSlots) {
		// check xs[i : i + nSlots]
		var lo = xs[i]
		var loCost = evaluate(i, i + nSlots, lo)
		var hi = xs[i + nSlots - 1]
		var hiCost = evaluate(i, i + nSlots, hi)
		while (hi - lo > 2) {
			var leftmid = lo + (hi - lo) / 3
			var leftmidCost = evaluate(i, i + nSlots, leftmid)
			var rightmid = hi - (hi - lo) / 3
			var rightmidCost = evaluate(i, i + nSlots, rightmid)

			if (leftmidCost == OO) {
				hi = leftmid
				hiCost = leftmidCost
			} else if (rightmidCost == OO) {
				hi = rightmid
				hiCost = rightmidCost
			} else if (leftmidCost < rightmidCost) {
				hi = rightmid
				hiCost = rightmidCost
			} else {
				lo = leftmid
				loCost = leftmidCost
			}
		}
		var midCost = evaluate(i, i + nSlots, (lo + hi) / 2)
		bestCost = min(bestCost, min(loCost, min(midCost, hiCost)))
	}
	println(bestCost)
}