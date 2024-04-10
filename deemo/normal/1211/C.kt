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
    val (n, k) = readInts()
    val segs = MutableList(n) {Pair(0L, 0L)}
    val cost = Array(n) {0L}
    var total = 0L
    var totalCost = 0L
    val rem = MutableList(0) {Pair(0L, 0L)}
    var mx = 0L
    for (i in 0 until n) {
        val (a, b, c) = readLongs()
        segs[i] = Pair(a, b)
        cost[i] = c
        total += a
        totalCost += 1L*a*c
        if (a < b)
            rem.add(b-a to c)
        mx += b
    }
    if (total > k || mx < k) {
        println("-1")
        return
    }
    rem.sortBy { it.second }
    var req = k - total
    for (x in rem) {
        val g = minOf(x.first, req)
        req -= g
        totalCost += g * x.second
    }
    println(totalCost)
}