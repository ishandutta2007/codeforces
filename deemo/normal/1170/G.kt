import java.lang.StringBuilder
import kotlin.math.atan

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
    val (n, m) = readInts()
    val from = IntArray(m) {0}
    val to = IntArray(m) {0}
    val del = BooleanArray(m) {false}
    val adj = Array(n) { MutableList(0) {0} }
    val pt = IntArray(n) {0}
    val sec = mutableListOf<Int>()

    for (i in 0 until m) {
        val (a, b) = readInts().map { it-1 }
        from[i] = a
        to[i] = b
        adj[a].add(i)
        adj[b].add(i)
    }

    fun dfs(v: Int) {
        while (pt[v] < adj[v].size) {
            val e = adj[v][pt[v]++]
            if (del[e]) continue

            del[e] = true
            val other = from[e] xor to[e] xor v
            dfs(other)
        }
        sec.add(v)
    }

    for (v in 0 until n)
        if (adj[v].size % 2 == 1) {
            println("NO")
            return
        }

    for (v in 0 until n)
        if (pt[v] != adj[v].size)
            dfs(v)

    addOL("YES")
    val gec = IntArray(sec.size) {0}
    var cur = 0
    val _OL = mutableListOf<String>()
    val vis = BooleanArray(n) {false}
    for (v in sec) {
        if (vis[v]) {
            val temp = mutableListOf(v+1)
            while (gec[cur-1] != v){
                cur--
                vis[gec[cur]] = false
                temp.add(gec[cur]+1)
            }
            temp.add(v+1)
            _OL.add(temp.size.toString() + " " + temp.joinToString(" "))
        }
        else{
            vis[v] = true
            gec[cur++] = v
        }
    }
    addOL(_OL.size.toString())
    OL.addAll(_OL)
    outputRes()
}