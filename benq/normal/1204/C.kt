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

val MX = 400005
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

val dist = Array(101, {IntArray(101)})

fun solve() {
    val n = nextInt()
    for (i in 1..n) {
        val s = next()
        for (j in 1..n) if (s[j-1] == '1') {
            dist[i][j] = 1
        } else if (j == i) dist[i][j] = 0
        else dist[i][j] = MOD
    }
    for (k in 1..n) for (i in 1..n) for (j in 1..n)
        dist[i][j] = minOf(dist[i][j],dist[i][k]+dist[k][j])
    val m = nextInt()
    val v = nextInts()
    val ret = arrayListOf(v[0])
    var cur = 0
    while (cur < v.size-1) {
        val CUR = cur
        while (cur < v.size && dist[v[CUR]][v[cur]] == cur-CUR) cur ++
        cur --
        ret.add(v[cur])
    }
    val out = StringBuilder()
    out.append(ret.size)
    out.append("\n")
    for (i in ret) {
        out.append(i)
        out.append(' ')
    }
    print(out)
}

fun main(args: Array<String>) {
    val T = 1
    for (i in 1..T) solve()
}