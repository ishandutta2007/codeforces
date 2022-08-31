/** useful links
 * https://kotlinlang.org/api/latest/jvm/stdlib/kotlin/-array/index.html
 * https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-list/index.html
 * https://kotlinlang.org/docs/reference/ranges.html
 */

/**
 * valid ways to sort:
 * 1
    * val a = nextLongs().sorted() // a is mutable list
 * 2
    * val a = arrayListOf<Long>()
    * a.addAll(nextLongs())
    * a.sort()
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

fun solve() {
    val n = nextInt()
    val a = nextInts()

    val T = TreeSet<Int>()
    var l = 0
    var ans = 0
    while (l < n && !T.contains(a[l])) {
        T.add(a[l++])
    }
    // println("HA $l")
    ans = l
    var r = n
    while (true) {
        while (r > l && !T.contains(a[r-1])) {
            T.add(a[--r])
        }
        ans = maxOf(ans,l+n-r)
        // println("$l and $r")
        if (l > 0) T.remove(a[--l])
        else break
    }

    print(n-ans)
}

fun main(args: Array<String>) {
    val T = 1
    for (i in 1..T) solve()
}