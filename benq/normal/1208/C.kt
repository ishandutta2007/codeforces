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
 */
// printing variables: println("$l and $r")

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

fun add(a: Int, b: Int) = (a + b) % MOD
fun sub(a: Int, b: Int) = (a - b + MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong() * b) % MOD).toInt()

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextInts() = next().split(" ").map { it.toInt() }
fun nextLongs() = next().split(" ").map { it.toLong() }

val ori = arrayOf(
                intArrayOf(8, 9, 1, 13),
                intArrayOf(3, 12, 7, 5),
                intArrayOf(0, 2, 4, 11),
                intArrayOf(6, 10, 15, 14)
               )
               
fun solve() {
    val n = nextInt()
    for (i in 0..n-1) {
        val sb = StringBuilder()
        for (j in 0..n-1) {
            val ad = 16*((i/4)*(n/4)+j/4)
            val v = ad+ori[i%4][j%4]
            sb.append(v)
            sb.append(" ")
        }
        println(sb)
    }
}

fun main(args: Array<String>) {
    val T = 1
    for (i in 1..T) solve()
}