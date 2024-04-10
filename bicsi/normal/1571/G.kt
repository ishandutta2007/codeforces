
fun main() {

    var (n, m) = readInts()
    data class Point(val i: Int, val a: Int, val b: Int)
    var all = mutableListOf<Point>()
    for (i in (0 until n)) {
        val k = readInt()
        val ai = readInts().toIntArray()
        val bi = readInts().toIntArray()
        for (j in 0 until k) {
            all.add(Point(i, ai[j], bi[j]))
        }
    }

    all.sortByDescending { (it.b).toLong() * n - it.i }

    val INF: Long = 1000000000000000000

    val T = LongArray(2 * (n + m) + 10) {-INF}
    var pos = m
    while (pos < T.size) {
        T[pos] = 0
        pos += (pos and (-pos));
    }

    var best: Long = 0
    for (p in all) {
//        println("${p.i} ${p.a} ${p.b}")
        var pos = p.b + p.i
        var ans: Long = -INF
        while (pos > 0) {
            ans = Math.max(ans, T[pos])
            pos -= (pos and (-pos));
        }
        if (ans >= 0) {
            ans += p.a
//            println(" => $ans")
            best = Math.max(best, ans)
            pos = p.b + p.i + 1
            while (pos < T.size) {
                T[pos] = Math.max(T[pos], ans)
                pos += (pos and (-pos))
            }
        }
    }

    println(best)
}

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints