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
    val ori = arrayOf(
        intArrayOf(8, 9, 1, 13),
        intArrayOf(3, 12, 7, 5),
        intArrayOf(0, 2, 4, 11),
        intArrayOf(6, 10, 15, 14)
    )
    val ori = Array(n, {IntArray(n)})
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

val DP = Array(200005,{LongArray(3)})

fun solve() {
    val (n,a,b) = nextInts()
    DP[0][1] = b.toLong()
    DP[0][2] = INF
    val s = next()
    for (i in 0..n-1) {
        if (s[i] == '1') {
            DP[i+1][1] = INF
            DP[i+1][2] = DP[i][2]+a+2*b
        } else {
            DP[i+1][1] = minOf(DP[i][1]+a,DP[i][2]+2*a)
            DP[i+1][2] = minOf(DP[i][1]+2*a,DP[i][2]+a)
            DP[i+1][1] = DP[i+1][1]+b
            DP[i+1][2] = DP[i+1][2]+2*b
        }
    }
    println(DP[n][1])
}

fun main(args: Array<String>) {
    val T = nextInt()
    for (i in 1..T) solve()
}