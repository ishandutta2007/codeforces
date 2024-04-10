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

fun add(a: Int, b: Int) = (a + b) % MOD
fun sub(a: Int, b: Int) = (a - b + MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong() * b) % MOD).toInt()

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextInts() = next().split(" ").map { it.toInt() }
fun nextLongs() = next().split(" ").map { it.toLong() }

val A = Array(50,{ IntArray(0)})
val B = Array(50,{ IntArray(50)})

fun solve() {
    val (n,m) = nextInts()
    for (i in 0..n-1) {
        A[i] = nextInts().toIntArray()
    }
    var num = 0
    val out = StringBuilder()
    for (i in 0..n-2) for (j in 0..m-2) {
        val sum = A[i][j]+A[i][j+1]+A[i+1][j]+A[i+1][j+1]
        if (sum == 4) {
            num ++
            out.append(i+1)
            out.append(" ")
            out.append(j+1)
            out.append("\n")
            B[i][j] = 1
            B[i+1][j] = 1
            B[i][j+1] = 1
            B[i+1][j+1] = 1
        }
    }
    for (i in 0..n-1) for (j in 0..m-1) if (A[i][j] != B[i][j]) {
        println(-1)
        System.exit(0)
    }
    println(num)
    println(out)
}

fun main(args: Array<String>) {
    val T = 1
    for (i in 1..T) solve()
}