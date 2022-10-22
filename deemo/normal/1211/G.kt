import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double

private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of long
private fun readDoubles() = readStrings().map { it.toDouble() } // list of double

private val OL = mutableListOf<String>()
private fun addOL(s: String){
    OL.add(s)
}
private fun outputRes() {
    println(OL.joinToString("\n"))
}

private val MAXN = 1e5.toInt()
private val MOD = 1e9.toInt() + 7

fun main() {
    val te = readInt()
    repeat(te) {
        val n = readInt()
        val col = readInts().toMutableList()
        val target = readInts()
        val adj = Array(n) { MutableList(0) {0}}
        repeat(n-1) {
            val (a, b) = readInts().map { it-1 }
            adj[a].add(b)
            adj[b].add(a)
        }

        val depth = IntArray(n) {0}
        fun plant(v: Int, p: Int = -1, de: Int = 0) {
            depth[v] = de
            for (u in adj[v])
                if (u != p)
                    plant(u, v, de + 1)
        }
        plant(0)

        val bad = BooleanArray(n) { col[it] != target[it] }
        var root = -1
        var cBad = 0
        for (i in 0 until n)
            if (bad[i]) {
                if (root == -1 || depth[root] < depth[i])
                    root = i
                cBad++
            }
        if (root == -1) {
            addOL("Yes")
            addOL("0")
        }
        else {
            var found = false
            var sec = IntArray(n) {0}
            var sz = 0
            fun dfs(v: Int, p: Int = -1, c: Int = 0) {
                sec[sz++] = v
                val cnt = if (bad[v]) c+1 else c

                if (cnt == cBad) {
                    found = true
                    return
                }

                for (u in adj[v])
                    if (u != p) {
                        dfs(u, v, cnt)
                        if (found) return
                    }
                sz--
            }
            dfs(root)
            if (found) {
                sec = sec.sliceArray(0 until sz)
                fun check(): Boolean {
                    for (i in 0 until sz - 1) {
                        val v = sec[i]
                        val u = sec[i+1]
                        col[u] = col[v].also { col[v] = col[u] }
                    }

                    var failed = false
                    for (i in 0 until n)
                        if (col[i] != target[i])
                            failed = true

                    if (!failed){
                        addOL("Yes")
                        addOL(sz.toString())
                        addOL(sec.slice(0 until sz).map { it+1 }.joinToString(" "))
                    }

                    for (i in sz-2 downTo 0) {
                        val v = sec[i]
                        val u = sec[i+1]
                        col[u] = col[v].also { col[v] = col[u] }
                    }
                    return !failed
                }
                if (!check()) {
                    sec.reverse()
                    if (!check()) {
                        addOL("No")
                    }
                }
            }
            else{
                addOL("No")
            }
        }
    }
    outputRes()
}