import java.lang.Math.*
import java.util.*

/**
 * Created by Administrator on 9/2/2019.
 */

// for (i in 1..n) {}
// for (i in 5 downTo 1)
// for (i in 1..5 step 2)
// println(n)
// println("${ansList.size} $ans")
// val freq = mutableMapOf<String, Int>()
// var places = mutableListOf<Place>()
// class Place(val x: Int, val b: Int)
// teams.sortWith(compareBy({it.size}));
// val pq = PriorityQueue<Team>(Comparator<Team>{a1, a2 -> a2.money - a1.money})
// var size = IntArray(402){0}
// var dp = Array(402, {IntArray(402)})
// var adj = MutableList<MutableList<Int>>(402) {_ -> mutableListOf()}
// println(Arrays.toString(array))
// println(Arrays.deepToString(array))
// Pair<Int, Int>
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of Longs

var dp = Array(17, {Array(46, {Array(46, {Array(32, {1000000})})})})
var S = ""

fun DP(at: Int, pos: Int, neg: Int, bc: Int): Int {
    if (at == 16) {
        if (bc == 0) return 0
        return 1000000
    }
    if (dp[at][pos][neg][bc + 16] != 1000000) {
        return dp[at][pos][neg][bc + 16]
    }
    dp[at][pos][neg][bc + 16] = 999999
    if (pos > 0) {
        var cur = DP(at, pos - 1, neg, bc)
        if (cur < dp[at][pos][neg][bc + 16]) dp[at][pos][neg][bc + 16] = cur
    }
    if (neg > 0) {
        var cur = DP(at, pos, neg - 1, bc)
        if (cur < dp[at][pos][neg][bc + 16]) dp[at][pos][neg][bc + 16] = cur
    }
    val now = bc + pos - neg
    var new_carry = 0
    if (now >= 0) new_carry = now / 10
    var new_borrow = 0
    if (now < 0) new_borrow = -((-now + 9) / 10)
    var last_degit = 0
    if (now >= 0) last_degit=now % 10
    else last_degit = (10 - (-now % 10)) % 10
    var expected = 0
    if (at < S.length) expected = (S[at] - '0').toInt()
    if (last_degit != expected) {
        return dp[at][pos][neg][bc + 16]
    }
    var cur = DP(at + 1, pos, neg, new_carry + new_borrow) + pos + neg
    if (cur < dp[at][pos][neg][bc + 16]) dp[at][pos][neg][bc + 16] = cur
    return dp[at][pos][neg][bc + 16]
}

fun main(args: Array<String>) {
    S = readLn()
    S = S.reversed()
    var ans = 30000
    for (pos in 0..45) for (neg in 0..45) {
        val cur = DP(0, pos, neg, 0)
        if (cur < ans) ans = cur
        //if (cur == 224) println("$pos $neg")
    }
    println(ans)
}