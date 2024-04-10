import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	val n = readInt()
	val xs = readInts()
	val numSequences = xs.count({it == -1})
	val lists: ArrayList<ArrayList<Int>> = ArrayList()
	val nextIndices: ArrayList<Int> = ArrayList()
	val done: ArrayList<Boolean> = ArrayList()
	for (i in 0..numSequences-1) {
		lists.add(ArrayList())
		nextIndices.add((i + 1) % numSequences)
		done.add(false)
	}
	var i = 0
	for ((index, x) in xs.withIndex()) {
		assert(!done[i])
		if (x == -1) {
			done[i] = true
		} else {
			lists[i].add(x)
		}
		if (index != xs.size - 1) {
			val oldI = i
			i = nextIndices[i]
			while (done[i]) {
				i = nextIndices[i]
			}
			nextIndices[oldI] = i
		}
	}
	println(numSequences)
	for (seq in lists) {
		print("${seq.size} ")
		println(seq.joinToString(" "))
	}
}