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
// var dp = Array(17, {Array(136, {Array(136, {Array(32, {1000000})})})})
// println(Arrays.toString(array))
// println(Arrays.deepToString(array))
// Pair<Int, Int>
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of Longs

fun main(args: Array<String>) {
    val n = readInt()
    var num = readInts()
    var z = num.sorted()
    var flag = 0
    for (i in 1..n-2) {
        if (z[0] < z[i] && z[i] < z[n - 1]) {
            for (j in 0..n-1) if (z[0] == num[j]) {print("${j+1} "); break}
            for (j in 0..n-1) if (z[i] == num[j]) {print("${j+1} "); break}
            for (j in 0..n-1) if (z[n - 1] == num[j]) {print("${j+1} "); break}
            return
        }
    }
    println("-1 -1 -1")
}