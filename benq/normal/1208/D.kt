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

val mn = LongArray(SZ)
val lazy = LongArray(SZ)

fun push(ind: Int, l: Int, r: Int) {
    if (lazy[ind] == 0L) return
    mn[ind] += lazy[ind]
    if (l != r) {
        lazy[2*ind] += lazy[ind]
        lazy[2*ind+1] += lazy[ind]
    }
    lazy[ind] = 0
}

fun upd(lo: Int,hi: Int,inc: Long,ind: Int,l: Int,r: Int) {
    push(ind,l,r)
    if (r < lo || hi < l) return
    if (lo <= l && r <= hi) {
        lazy[ind] += inc
        push(ind,l,r)
        return
    }
    val m = (l+r)/2
    upd(lo,hi,inc,2*ind,l,m)
    upd(lo,hi,inc,2*ind+1,m+1,r)
    mn[ind] = minOf(mn[2*ind],mn[2*ind+1])
}

fun lastZero(ind: Int, l: Int, r: Int) : Int {
    push(ind,l,r)
    if (l == r) return l
    val m = (l+r)/2
    push(2*ind+1,m+1,r)
    if (mn[2*ind+1] == 0L) return lastZero(2*ind+1,m+1,r)
    return lastZero(2*ind,l,m)
}

fun solve() {
    val n = nextInt()
    val s = nextLongs()
    for (i in 0..n-1) upd(i,i,s[i],1,0,n-1)
    val ans = IntArray(n)
    for (i in 1..n) {
        val x = lastZero(1,0,n-1)
        ans[x] = i
        /*println("HA $x")

        print(mn[1])
        print(" ")
        print(mn[2])
        print(" ")
        print(mn[3])
        println()*/

        upd(x,x,(1e18).toLong(),1,0,n-1)

        /*print(mn[1])
        print(" ")
        print(mn[2])
        print(" ")
        print(mn[3])
        println()*/

        upd(x,n-1,(-i).toLong(),1,0,n-1)

        /*print(mn[1])
        print(" ")
        print(mn[2])
        print(" ")
        print(mn[3])
        println()*/
    }
    val out = StringBuilder()
    for (i in 0..n-1) {
        out.append(ans[i])
        out.append(" ")
    }
    print(out)
}

fun main(args: Array<String>) {
    val T = 1
    for (i in 1..T) solve()
}