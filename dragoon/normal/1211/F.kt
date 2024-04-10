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

var adj = MutableList<MutableList<MutableList<Int>>>(6) {_ -> MutableList<MutableList<Int>>(6){_ -> mutableListOf()}}

fun solve(id: Int, j_: Int) {
    var ans = mutableListOf<Int>()
    var stId = Stack<Int>()
    var stJ = Stack<Int>()
    stJ.add(j_)
    stId.add(id)
    while (stJ.size > 0) {
        var j= stJ.peek()
        var done = 0
        for (k in 0..5) {
            if (adj[(j + 1)%6][k].size > 0) {
                stId.add(adj[(j + 1)%6][k].last())
                stJ.add(k)
                adj[(j + 1)%6][k].removeAt(adj[(j + 1)%6][k].size - 1)
                done = 1
                break
            }
        }
        if (done == 1) continue
        stJ.pop()
        ans.add(stId.peek())
        stId.pop()
    }
    ans = ans.asReversed()
    for (i in ans) print("${i} ")
}

fun main(args: Array<String>) {
    val n = readInt()
    for (i in 1..n) {
        val S = readLn()
        var pre = "kotlin".indexOf(S[0])
        var suf = "kotlin".indexOf(S[S.length - 1])
        adj[pre][suf].add(i)
    }
    for (i in 0..5) {
        while (adj[0][i].size > 0) {
            var j = adj[0][i].size - 1
            var t = adj[0][i][j]
            adj[0][i].removeAt(j)
            solve(t, i)
        }
    }
}