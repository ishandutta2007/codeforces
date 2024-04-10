import java.lang.Math.*
import java.math.BigInteger
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
// var dp = Array(17, {Array(136, {Array(136, {Array(32, {1000000})})})})
// println(Arrays.toString(array))
// println(Arrays.deepToString(array))
// Pair<Int, Int>
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of Longs

class Ice(val u: Long, val c: Long)
var ice = mutableListOf<Ice>()

fun main(args: Array<String>) {
    val (n, k) = readInts()
    var total_cost = 0L
    var total_cnt = 0L
    var max_cnt = 0L
    for (i in 0..n-1) {
        val (a,b,c) = readInts()
        max_cnt += b
        total_cnt += a
        total_cost += 1L * a * c
        ice.add(Ice(b - a + 0L, c + 0L))
    }
    if (total_cnt > k || max_cnt < k) {
        println(-1)
        return
    }
    ice.sortWith(compareBy({it.c}))
    for (i in 0..n-1) {
        val will_take = min(k - total_cnt, ice[i].u)
        total_cnt += will_take
        total_cost += 1L * will_take * ice[i].c

    }
    println(total_cost)
}