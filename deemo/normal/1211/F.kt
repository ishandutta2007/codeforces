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
    val n = readInt()
    val tt = "kotlin"
    val mp = hashMapOf<Char, Int>()
    for ((i, c) in tt.withIndex())
        mp[c] = i

    val s = Array(n) {String()}
    val from = IntArray(n)
    val to = IntArray(n)
    val adj = Array(10) { MutableList(0) {0}}
    for (i in 0 until n) {
        s[i] = readLn()
        from[i] = mp[s[i][0]]!!
        to[i] = mp[s[i].last()]!!
        to[i] = (to[i]+1)%6
        adj[from[i]].add(i)
    }

    val pt = IntArray(10) {0}

    val ans = mutableListOf<Int>()
    fun dfs(v: Int, parE: Int = -1) {
        while (pt[v] < adj[v].size) {
            val e = adj[v][pt[v]++]
            dfs(to[e] xor from[e] xor v, e)
        }
        if (parE != -1)
            ans.add(parE)
    }

    dfs(0)
    ans.reverse()
    println(ans.map { it+1 }.joinToString(" "))
}