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
    val (m, n) = readInts()
    val a = readInts()
    val q = readInt()
    val pt = IntArray(m+1) {0}
    for (i in 1..m)
        pt[i] = pt[i-1] + a[i-1]

    repeat(q) {
        val p = readInts()
        var last = 0
        var cur = 0
        for (i in 1 until p.size) {
            val d = p[i] - last - 1

            var (lo, hi) = Pair(cur, m+1)
            while (hi-lo>1){
                val mid = (hi+lo)/2
                if (pt[mid] - pt[cur] <= d)
                    lo = mid
                else
                    hi = mid
            }
            cur = lo

            last = p[i]
        }

        val d = n-last
        var (lo, hi) = Pair(cur, m+1)
        while (hi-lo>1){
            val mid = (hi+lo)/2
            if (pt[mid] - pt[cur] <= d)
                lo = mid
            else
                hi = mid
        }
        cur = lo

        addOL(if (cur == m) "YES" else "NO")
    }
    outputRes()
}