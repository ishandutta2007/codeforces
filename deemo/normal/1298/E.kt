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
    val s = readInts()
    val adj = Array(n) { arrayListOf<Int>() }
    repeat(m) {
        val (a, b) = readInts().map { it-1 }
        adj[a].add(b)
        adj[b].add(a)
    }
    val sec = IntArray(n).toMutableList()
    for (i in 0 until n)
        sec[i] = i
    sec.sortWith(compareBy { s[it] })

    val ans = IntArray(n)
    var same = 0
    for (i in 0 until n) {
        val v = sec[i]
        if (i > 0 && s[v] == s[sec[i-1]])
            same++
        else
            same = 1
        ans[v] = i + 1 - same
        for (u in adj[v])
            if (s[u] < s[v])
                ans[v]--
    }

    addOL(ans.joinToString(" "))
    outputRes()
}