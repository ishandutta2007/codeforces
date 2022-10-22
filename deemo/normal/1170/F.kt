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
    val (n, m, k) = readInts()
    val a = readInts().sorted()
    val pt = LongArray(n+1) {0L}
    for (i in 0 until n)
        pt[i+1] = pt[i] + a[i]

    fun getUp(l: Int, dest: Int): Long {
        return 1L * a[dest] * (dest - l + 1) - (pt[dest+1] - pt[l])
    }

    fun get(l: Int, dest: Int): Long {
        var (lo, hi) = Pair(l, l + m)
        while (hi-lo>1){
            val mid = (hi+lo)/2
            if (a[mid] <= dest)
                lo = mid
            else
                hi = mid
        }

        var ret = 1L * dest * (hi - l) - (pt[hi] - pt[l])
        ret += (pt[l + m] - pt[hi]) - 1L * (l+m - hi) * dest
        return ret
    }

    fun ok(l: Int, mid: Int): Boolean {
        return getUp(l, mid) <= k
    }

    var ans = Long.MAX_VALUE
    val md = (m-1)/2
    for (l in 0..n-m) {
        val ideal = l + md
        var (lo, hi) = Pair(l, ideal+1)
        while (hi-lo>1){
            val mid = (hi+lo)/2
            if (ok(l, mid))
                lo = mid
            else
                hi = mid
        }


        var rem = k.toLong() - getUp(l, lo)
        rem /= (hi - l)
        if (lo == ideal)
            rem = 0L
        ans = minOf(ans, get(l, a[lo] + rem.toInt()))
    }
    println(ans)
}