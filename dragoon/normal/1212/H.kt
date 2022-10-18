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
// var dp = Array(402, {IntArray(402)})
// var adj = MutableList<MutableList<Int>>(402) {_ -> mutableListOf()}
// println(Arrays.toString(array))
// println(Arrays.deepToString(array))
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of Longs

var dp = Array(402, {IntArray(402)})
var adj = MutableList<MutableList<Pair<Int, Int>>>(402) {_ -> mutableListOf()}
var dpAns = MutableList<MutableList<MutableList<Int>>>(402) {_ -> MutableList<MutableList<Int>>(402){_ -> mutableListOf()}}
var size = IntArray(402){0}

fun DP(at: Int, par: Int) {
    size[at] = 1
    dp[at] = IntArray(402) {-1}
    dp[at][1] = 0
    for (V in adj[at]) {
        val v = V.first
        if (par == v) continue
        DP(v, at)
        dp[v][0] = 1
        dpAns[v][0].add(V.second)
        var newDp = IntArray(402) {-1}
        var prev = IntArray(402) {-1}
        for (i in 1..size[at]) {
            for (j in 0..size[v]) {
                if (dp[at][i] == -1 || dp[v][j] == -1) continue
                val cur = dp[at][i] + dp[v][j]
                if (newDp[i + j] == -1 || newDp[i + j] > cur) {
                    prev[i + j] = i
                    newDp[i + j] = cur
                }
            }
        }
        dp[at] = newDp
        var newDpAns = MutableList<MutableList<Int>>(402) {_ -> mutableListOf()}
        for (i in 0..size[at]+size[v]) {
            if (prev[i] != -1) {
                newDpAns[i].addAll(dpAns[at][prev[i]])
                newDpAns[i].addAll(dpAns[v][i - prev[i]])
            }
        }
        dpAns[at] = newDpAns
        size[at] += size[v]
        for (i in 1..size[v]) {
            dp[v][i]++
            dpAns[v][i].add(V.second)
        }
    }
}

fun main(args: Array<String>) {
    val (n, k) = readInts()
    for (i in 1..n-1) {
        val (u, v) = readInts()
        adj[u].add(Pair(v, i))
        adj[v].add(Pair(u, i))
    }
    DP(1, 0)
    var best = -1
    var bestAns = MutableList<Int>(402) {-1}
    for (i in 1..n) {
        if (dp[i][k] == -1) continue
        if (best == -1 || best > dp[i][k]) {
            best = dp[i][k]
            bestAns = dpAns[i][k]
        }
    }
    println(best)
    for (i in bestAns) print("$i ")
}