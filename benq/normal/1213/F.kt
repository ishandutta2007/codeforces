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

fun solve() {
    val (n,k) = nextInts()
    val p = nextInts()
    val q = nextInts()
    val P = IntArray(n)
    val Q = IntArray(n)
    val cum = IntArray(n)
    for (i in 0..n-1) {
        P[p[i]-1] = i
        Q[q[i]-1] = i
    }
    for (i in 0..n-1) {
        var x = P[i]
        var y = Q[i]
        if (x > y) {
            val tmp = x
            x = y
            y = tmp
        }
        cum[x] ++
        cum[y] --
    }
    val zero = ArrayList<Int>()
    for (i in 0..n-1) {
        if (i > 0) cum[i] += cum[i-1]
        if (cum[i] == 0) zero.add(i)
    }
    if (zero.size < k) {
        print("NO")
        System.exit(0)
    }
    var lst = -1
    var cnt = 0
    val ans = StringBuilder()
    for (i in 0..n-1) ans.append('.')
    for (t in zero) {
        for (i in lst+1..t) {
            ans[p[i]-1] = ('a'+cnt).toChar()
        }
        lst = t
        cnt ++
        cnt = minOf(cnt,25)
    }
    println("YES")
    print(ans)
}

fun main(args: Array<String>) {
    val T = 1
    for (i in 1..T) solve()
}