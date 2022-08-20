// kotlin tips b/c I'm bad

/** useful links
 * https://kotlinlang.org/api/latest/jvm/stdlib/kotlin/-array/index.html
 * https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-list/index.html
 * https://kotlinlang.org/docs/reference/ranges.html
 */

/** valid ways to sort (don't use quicksort ...)
 * 1
 * val a = nextLongs().sorted() // a is mutable list
 * 2
 * val a = arrayListOf<Long>()
 * a.addAll(nextLongs())
 * a.sort()
 */

/** declare 2D array
    * val ori = Array(n, {IntArray(n)})
    * val ori = arrayOf(
        intArrayOf(8, 9, 1, 13),
        intArrayOf(3, 12, 7, 5),
        intArrayOf(0, 2, 4, 11),
        intArrayOf(6, 10, 15, 14)
      )
 */

/** printing variables:
 * println("${l+1} and $r")
 * evidently print has high constant factor
 * print stringbuilder instead?
 */

// ArrayList to Array: toArray

// IntArray with size:
// val arr = IntArray(1 shl 20, { 1 })

// lower bound: use binary search
// https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/binary-search.html

// if/switch
// https://kotlinlang.org/docs/reference/control-flow.html

// swap:
// https://kotlinlang.org/api/latest/jvm/stdlib/kotlin/also.html
// a = b.also { b = a }

/** comparing pairs
 * val ed = ArrayList<Pair<Int,Pair<Int,Int>>>()
   ed.sortBy {it.first}
 *  class CustomComparator : Comparator<Pair<Int,Pair<Int,Int>>> {
        override fun compare(o1: Pair<Int,Pair<Int,Int>>, o2: Pair<Int,Pair<Int,Int>>): Int {
            return o1.first.compareTo(o2.first)
        }
    }
    val v = ed.sortedWith(CustomComparator())
 *
    val v = ArrayList<Pair<Int,Long>>()
    for (t in a) v.add(Pair(cat(t),t))
    val z = v.sortedWith(compareBy({ -it.first }, { it.second }))
 */

/** hashmap
 *  val h = HashMap<String,Int>()
    for (i in 0..n-2) {
        val w = s.substring(i,i+2)
        val c = h.getOrElse(w){0}
        h.put(w,c+1)
    }
 */

import java.util.*

val MX = 1000005
val MOD = 998244353
val SZ = 1 shl 19
val INF = (1e18).toLong()

fun add(a: Int, b: Int) = (a + b) % MOD
fun sub(a: Int, b: Int) = (a - b + MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong() * b) % MOD).toInt()

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextInts() = next().split(" ").map { it.toInt() }
fun nextLongs() = next().split(" ").map { it.toLong() }

val dp = DoubleArray(1001)
val pre = IntArray(1001)
var bad = Array<DoubleArray>(1001,{DoubleArray(1001)})
var n = 0
var l = 0
val a = arrayListOf<Pair<Int,Int>>()

fun ok(mid: Double): Boolean {
    for (i in 1..n) {
        dp[i] = 1e18
        for (j in 0..i-1) {
            val ex = dp[j]+bad[j][i]
            if (ex < dp[i]) {
                dp[i] = ex
                pre[i] = j
            }
        }
        dp[i] -= mid*a[i].second
    }
    return dp[n] <= 0
}

fun construct(mid: Double) {
    ok(mid)
    var cur = n
    val ans = arrayListOf<Int>()
    while (cur != 0) {
        ans.add(cur)
        cur = pre[cur]
    }
    val ret = ans.reversed()
    for (t in ret) print("$t ")
}


fun solve() {
    val (N,L) = nextInts()
    n = N
    l = L
    a.add(Pair(0,0))
    for (i in 1..n) {
        val (x,b) = nextInts()
        a.add(Pair(x,b))
    }
    for (i in 1..n) for  (j in 0..i-1) {
        var dif: Double = (a[i].first-a[j].first-l).toDouble()
        bad[j][i] = Math.sqrt(Math.abs(dif))
    }
    var lo = 0.0
    var hi = 1e7
    for (i in 1..50) {
        val mid = (lo+hi)/2
        if (ok(mid)) hi = mid
        else lo = mid
    }
    construct(lo)
}

fun main(args: Array<String>) {
    val T = 1
    for (i in 1..T) solve()
}