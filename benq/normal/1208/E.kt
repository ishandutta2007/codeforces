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

val dist = Array(101, {IntArray(101)})

val cum = LongArray(MX)

var L = 0
var R = 0

var n = 0
var w = 0

var d : Deque<Pair<Int,Int>> = LinkedList()

fun ins(x: Int) {
    R ++
    while (d.size > 0 && d.getLast().first <= x) d.removeLast()
    d.addLast(Pair(x,R))
}

fun del() {
    if (d.getFirst().second == L) d.removeFirst()
    L ++;
}

fun mx() : Int {
    return d.getFirst().first
}

fun ad(l: Int, r: Int, v: Int) {
    cum[l] = cum[l]+v
    cum[r+1] = cum[r+1]-v
}

fun check(i: Int, a: List<Int>, l: Int) : Int {
    val lef = maxOf(l-w+i,0)
    val rig = minOf(i,l-1)
    while (R < rig) ins(a[R+1])
    while (L < lef) del()
    // println("$lef $rig $L $R ${mx()}")
    var m = mx()
    if (i >= l || w-1-i >= l) m = maxOf(m,0)
    return m
}

fun process() {
    L = 0
    R = -1
    d = LinkedList()
    val a = nextInts().drop(1)
    val l = a.size
    //print(l)
    //System.exit(0)
    if (2*l < w) {
        for (i in 0..l-1) {
            val m = check(i,a,l)
            ad(i,i,m)
        }
        val m = check(l,a,l)
        ad(l,w-1-l,m)
        for (i in w-l..w-1) {
            val m = check(i,a,l)
            ad(i,i,m)
        }
    } else {
        for (i in 0..w-1) {
            val m = check(i,a,l)
            ad(i,i,m)
        }
    }
    // System.exit(0)
}

fun solve() {
    val (N,W) = nextInts()
    n = N
    w = W
    for (i in 0..n-1) process()
    val out = StringBuilder()
    for (i in 0..w-1) {
        if (i > 0) cum[i] += cum[i-1]
        out.append(cum[i])
        out.append(' ')
    }
    print(out)
}

fun main(args: Array<String>) {
    val T = 1
    for (i in 1..T) solve()
}