// kotlin tips b/c I'm bad

/** useful links
 * https://kotlinlang.org/api/latest/jvm/stdlib/kotlin/-array/index.html
 * https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-list/index.html
 * https://kotlinlang.org/docs/reference/ranges.html
 */

/** valid ways to sort
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
 * println("$l and $r")
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
fun nextInts() = next().split(" ").map { it.toInt() }
fun nextLongs() = next().split(" ").map { it.toLong() }

val ed = ArrayList<Pair<Int,Pair<Int,Int>>>()
val par = IntArray(MX)
val sz = LongArray(MX)

fun get(x: Int): Int {
    if (par[x] != x) {
        par[x] = get(par[x])
        return par[x]
    }
    return x
}

fun unite(x: Int, y: Int) {
    sz[x] += sz[y]
    par[y] = x
}

fun solve() {
    val (n,m) = nextInts()
    for (i in 1..n) {
        par[i] = i
        sz[i] = 1
    }
    for (i in 1..n-1) {
        val (u,v,w) = nextInts()
        ed.add(Pair(w,Pair(u,v)))
    }
    ed.sortBy {it.first}
    val keys = ArrayList<Int>()
    val vals = ArrayList<Long>()
    var cur: Long = 0
    for (t in ed) {
        val x = get(t.second.first)
        val y = get(t.second.second)
        cur += sz[x]*sz[y]
        unite(x,y)
        if (keys.size > 0 && keys[keys.size-1] == t.first) {
            keys.removeAt(keys.size-1)
            vals.removeAt(vals.size-1)
        }
        keys.add(t.first)
        vals.add(cur)
    }
    /*for (t in keys) print("$t ")
    println()
    for (t in vals) print("$t ")
    println()*/
    val Q = nextInts()
    for (q in Q) {
        var ans : Long = 0
        // for (t in w) if (t.first <= q) ans = t.second
        var pos = keys.binarySearch(q)
        if (pos < 0) pos = -pos-2
        if (pos < 0) print(0)
        else print(vals[pos])
        print(" ")
    }
}

fun main(args: Array<String>) {
    val T = 1
    for (i in 1..T) solve()
}