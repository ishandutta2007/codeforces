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
    val t = readInt()
    repeat(t) {
        val (n, k) = readInts()
        val adj = Array(n) { mutableListOf<Int>() }
        val del = BooleanArray(n) {false}
        val deg = IntArray(n) {0}
        repeat(n-1) {
            val (a, b) = readInts().map { it-1 }
            adj[a].add(b)
            adj[b].add(a)
        }
        var count = 0
        val q = mutableListOf<Int>()
        for (v in 0 until n) {
            if (adj[v].size <= 1) {
                count++
                q.add(v)
            }
            deg[v] = adj[v].size
        }

        if (count < k)
            addOL("No")
        else {
            addOL("Yes")
            var ptr = 0
            while (count > k) {
                val v = q[ptr++]
                count--
                del[v] = true
                for (u in adj[v])
                    if (!del[u]) {
                        deg[u]--
                        if (deg[u] == 1) {
                            q.add(u)
                            count++
                        }
                    }
            }
            val res = mutableListOf<Int>()
            for (v in 0 until n)
                if (!del[v])
                    res.add(v+1)
            addOL("${res.size}")
            addOL(res.joinToString(" "))
        }
    }
    outputRes()
}