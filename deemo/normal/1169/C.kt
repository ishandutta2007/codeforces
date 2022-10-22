private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val (n, m) = readInts()
    val a = readInts()

    fun ok(mid: Int): Boolean {
        var last = 0
        for (x in a) {
            if (last > x + mid)
                return false

            last = if (last >= x || last + (m-x) <= mid) last else x
        }
        return true
    }

    var (lo, hi) = listOf(-1, m-1)
    while (hi - lo > 1) {
        val mid = (hi+lo)/2
        when (ok(mid)) {
            true -> hi = mid
            false -> lo = mid
        }
    }
    println(hi)
}