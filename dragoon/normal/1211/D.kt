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

var vis = IntArray(1000006, {0})
var cnt = IntArray(1000006, {0})
var list = mutableListOf<Int>()

fun solve(a_: Int, b_: Int): Int {
    var a = a_
    var b = b_
    if (a < b) {
        list = list.asReversed()
        var c = a
        a = b
        b = c
    }

    var ret = 0
    for (i in 0..list.size-2) {
        var cur = min(list[i]/a, list[i + 1]/b)
        ret += cur
        list[i + 1] -= cur * b
    }
    return ret
}

fun main(args: Array<String>) {
    val (n, a, b, k) = readInts()
    val num = readInts()
    for (i in 0..n-1) {
        cnt[num[i]]++
    }
    var ans = 0
    if (a > b) {
        for (i in 1..1000000) {
            if (vis[i] == 1) continue
            var now = i
            while (now * k <= 1000000) {
                vis[now] = 1
                var cur = min(cnt[now]/a, cnt[now * k] / b)
                cnt[now * k] -= b * cur
                ans += cur
                now = now * k
            }
        }
    } else {
        for (i in 1000000 downTo 1) {
            if (vis[i] == 1) continue
            var now = i
            while (now % k == 0) {
                vis[now] = 1
                var cur = min(cnt[now]/b, cnt[now / k] / a)
                cnt[now / k] -= a * cur
                ans += cur
                now = now / k
            }
        }
    }
    println(ans)
}