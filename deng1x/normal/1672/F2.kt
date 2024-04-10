var total = 0

fun dfs(u: Int, graph: List<List<Int>>, visited: BooleanArray, order: IntArray): Boolean {
    visited[u] = true
    for (v in graph[u]) {
        if (visited[v]) continue
        if (!dfs(v, graph, visited, order)) {
            return false
        }
    }
    order[u] = ++total
//    for (v in graph[u]) {
//        if (order[v] >= order[u]) {
//            return false
//        }
//    }
    return true
}

fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()!!.toInt()
        val a = readLine()!!.split(" ").map { it.toInt() }
        val b = readLine()!!.split(" ").map { it.toInt() }

        val countA = IntArray(a.size + 1)
        a.forEach { countA[it]++ }

        val maxOccur = a.sortedBy { it }.maxByOrNull { countA[it] }!!

        val edge = List<MutableList<Int>>(a.size + 1) { mutableListOf() }
        val vis = BooleanArray(a.size + 1)
        val order = IntArray(a.size + 1)
        for (i in a.indices) {
            if (a[i] != maxOccur && b[i] != maxOccur) {
                edge[a[i]].add(b[i])
            }
        }
        for (i in 1..a.size) {
            if (!vis[i]) {
                dfs(i, edge, vis, order)
            }
        }
        for (i in 1..a.size) {
            for (j in edge[i]) {
                if (order[j] >= order[i]) {
                    println("WA")
                    return@repeat
                }
            }
        }
        println("AC")
    }
}