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
        val a = readInts()
        val sec = MutableList(n) {it}
        sec.sortWith(compareBy { a[it] })
        val ans = MutableList(n) {0}

        fun check(mid: Int): Boolean {
            ans[sec[n-1]] = mid
            var rem = k - mid
            for (i in n-2 downTo  0) {
                val g = minOf(rem, a[sec[i+1]] + ans[sec[i+1]] - a[sec[i]] - 1)
                rem -= g
                ans[sec[i]] = g
            }
            return rem == 0
        }

        var lo = -1
        var hi = k

        while (hi - lo > 1) {
            val mid = (hi + lo)/ 2
            if (check(mid))
                hi = mid
            else
                lo = mid
        }

        check(hi)
        addOL(ans.joinToString(" "))
    }
    outputRes()
}