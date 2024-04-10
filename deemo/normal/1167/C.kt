private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val (n, m) = readInts()
    val adj = ArrayList<ArrayList<Int>>()
    for (i in 0 until n)
        adj.add(ArrayList())

    repeat(m) {
        val inp = readInts().map { it-1 }
        for (i in 2 until inp.size) {
            adj[inp[i]].add(inp[i-1])
            adj[inp[i-1]].add(inp[i])
        }
    }

    val vis = Array(n){false}
    val ans = MutableList(n){it}
    val comp = MutableList(n){0}
    var cur = 0

    fun dfs(v: Int) {
        vis[v] = true
        comp[cur]++
        ans[v] = cur
        for (u in adj[v])
            if (!vis[u])
                dfs(u)
    }

    for (v in 0 until n)
        if (!vis[v]) {
            dfs(v)
            cur++
        }

    println(ans.map { comp[it] }.joinToString(" "))
}