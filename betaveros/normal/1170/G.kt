import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

data class Edge(val a: Int, val b: Int, var used: Boolean) {
	fun other(v: Int): Int {
		if (v == a) return b
		assert(v == b)
		return a
	}
}

fun main(args: Array<String>) {
	val (nVertices, nEdges) = readInts()
	val graph: ArrayList<ArrayList<Int>> = ArrayList() // holds index of edges!
	val edges: ArrayList<Edge> = ArrayList()
	val edgeProgress: ArrayList<Int> = ArrayList()
	val inStack: ArrayList<Boolean> = ArrayList()
	repeat(nVertices) {
		graph.add(ArrayList())
		edgeProgress.add(0)
		inStack.add(false)
	}
	for (ei in 0..nEdges-1) {
		val (a, b) = readInts()
		graph[a-1].add(ei)
		graph[b-1].add(ei)
		edges.add(Edge(a-1, b-1, false))
	}

	if (graph.any { it.size % 2 != 0 }) {
		println("NO")
		return
	}

	val stack: ArrayList<Int> = ArrayList()

	val popLogs: ArrayList<ArrayList<Int>> = ArrayList()
	for (rootv in 0..nVertices-1) {
		// println("rootv: $rootv")
		while (edgeProgress[rootv] < graph[rootv].size) {
			if (edges[graph[rootv][edgeProgress[rootv]]].used) {
				edgeProgress[rootv]++
			} else {
				stack.add(rootv)
				inStack[rootv] = true
				var popGoal: Int? = null
				var popLog: ArrayList<Int> = ArrayList()
				while (stack.size > 0) {
					// println("stack is $stack, popGoal is $popGoal")
					if (popGoal == null) {
						val top = stack.last()
						while (edgeProgress[top] < graph[top].size && edges[graph[top][edgeProgress[top]]].used) {
							edgeProgress[top]++
						}
						if (edgeProgress[top] == graph[top].size) {
							// println("breaking. Stack: $stack")
							for (v in stack) {
								inStack[v] = false
							}
							stack.clear()
							break
						}
						val nextV = edges[graph[top][edgeProgress[top]]].other(top)
						edges[graph[top][edgeProgress[top]]].used = true
						edgeProgress[top]++
						if (inStack[nextV]) {
							popGoal = nextV
							popLog.add(nextV)
						} else {
							stack.add(nextV)
							inStack[nextV] = true
						}
					} else {
						val top = stack.last()
						popLog.add(top)
						if (top == popGoal) {
							popGoal = null
							// println("Logging $popLog")
							popLogs.add(popLog)
							popLog = ArrayList()
						} else {
							inStack[top] = false
							stack.removeAt(stack.size - 1)
						}
					}
				}
			}
		}
	}
	println("YES")
	println(popLogs.size)
	for (log in popLogs) {
		print("${log.size} ")
		println(log.map { it + 1 }.joinToString(" "))
	}
}