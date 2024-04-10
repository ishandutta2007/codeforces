import java.lang.StringBuilder
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
    val n = readInt()
    val a = readInts()
    val mp = TreeMap<Int, Int>()
    for (x in a) {
        if (x in mp)
            mp[x] = mp[x]!! + 1
        else
            mp[x] = 1
    }

    fun good(mid: Int): String {
        for (i in 1..mid)
            if (mp[i] != 2)
                return "X"

        val res = StringBuilder()
        val sec = mutableListOf<Int>()
        var cur = 0
        for (i in 0 until n) {
            if (a[i] in 1..mid) {
                if (cur < sec.size && a[i] == sec[cur]) {
                    cur++
                    res.append('G')
                }
                else {
                    sec.add(a[i])
                    res.append('R')
                }
            }
            else
                res.append('B')
        }
        if (sec.size != mid || cur != mid)
            return "X"
        return res.toString()
    }

    var (lo, hi) = mutableListOf(0, n)
    while (hi-lo>1) {
        val mid = (hi+lo)/ 2
        if (good(mid)[0] == 'X')
            hi = mid
        else
            lo = mid
    }
    println(good(lo))
}