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

var n = 0

fun check(x: String, s: String, t: String) {
    for (i in 0..x.length-2) {
        if (x.substring(i,i+2) == s) return
        if (x.substring(i,i+2) == t) return
    }
    println("YES")
    print(x)
    System.exit(0)
}

fun gen(x: String) : String {
    val v = StringBuilder()
    for (i in 1..n) v.append(x)
    return v.toString()
}

fun GEN(x: String, y: String, z: String) : String {
    val v = StringBuilder()
    for (i in 1..n) v.append(x)
    for (i in 1..n) v.append(y)
    for (i in 1..n) v.append(z)
    return v.toString()
}

fun solve() {
    n = nextInt()
    val s = next()
    val t = next()
    check(gen("abc"),s,t)
    check(gen("cba"),s,t)
    check(GEN("a","b","c"),s,t)
    check(GEN("a","c","b"),s,t)
    check(GEN("b","c","a"),s,t)
    check(GEN("b","a","c"),s,t)
    check(GEN("c","a","b"),s,t)
    check(GEN("c","b","a"),s,t)
}

fun main(args: Array<String>) {
    val T = 1
    for (i in 1..T) solve()
}