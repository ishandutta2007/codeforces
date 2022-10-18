import java.lang.Math.*

/**
 * Created by Administrator on 9/2/2019.
 */

// for (i in 1..n) {}
// for (i in 5 downTo 1)
// for (i in 1..5 step 2)
// println(n)
// val freq = mutableMapOf<String, Int>()
// var places = mutableListOf<Place>()
// class Place(val x: Int, val b: Int)

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of Longs

class Place(val x: Int, val b: Int)

fun main(args: Array<String>) {
    val (n, l) = readInts()
    var places = mutableListOf<Place>()
    for (i in 1..n) {
        val (x, b) = readInts()
        places.add(Place(x, b))
    }
    var lo = 0.0
    var hi = sqrt(abs(places[n - 1].x - l).toDouble())/(places[n - 1].b)
    var dp = DoubleArray(n)
    var par = IntArray(n)
    for (z in 1..50) {
        var mid = (lo + hi) / 2
        for (i in 0..n-1) {
            dp[i] = sqrt(abs(places[i].x - l).toDouble()) - mid * (places[i].b)
            par[i] = -1
            for (j in 0..i-1) {
                var cur = dp[j] + sqrt(abs(places[i].x - places[j].x - l).toDouble()) - mid * (places[i].b)
                if (cur < dp[i]) {
                    dp[i] = cur
                    par[i] = j
                }
            }
        }

        if (dp[n - 1] < 0) hi = mid
        else lo = mid
    }

    //println(lo)
    var ans = mutableListOf<Int>()
    var cur = n - 1
    while (cur != -1) {
        ans.add(cur + 1)
        cur = par[cur]
    }
    ans = ans.asReversed()
    for (i in ans) print(" ${i}")

}