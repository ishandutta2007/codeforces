// kotlin tips b/c I'm bad

/** useful links
 * https://kotlinlang.org/api/latest/jvm/stdlib/kotlin/-array/index.html
 * https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-list/index.html
 * https://kotlinlang.org/docs/reference/ranges.html
 */

/** valid ways to sort (don't use quicksort ...)
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
 * println("${l+1} and $r")
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

// swap:
// https://kotlinlang.org/api/latest/jvm/stdlib/kotlin/also.html
// a = b.also { b = a }

/** comparing pairs
 * val ed = ArrayList<Pair<Int,Pair<Int,Int>>>()
ed.sortBy {it.first}
 *  class CustomComparator : Comparator<Pair<Int,Pair<Int,Int>>> {
override fun compare(o1: Pair<Int,Pair<Int,Int>>, o2: Pair<Int,Pair<Int,Int>>): Int {
return o1.first.compareTo(o2.first)
}
}
val v = ed.sortedWith(CustomComparator())
 *
val v = ArrayList<Pair<Int,Long>>()
for (t in a) v.add(Pair(cat(t),t))
val z = v.sortedWith(compareBy({ -it.first }, { it.second }))
 */

/** hashmap
 *  val h = HashMap<String,Int>()
for (i in 0..n-2) {
val w = s.substring(i,i+2)
val c = h.getOrElse(w){0}
h.put(w,c+1)
}
 */

import java.util.*

val MX = 200005
val MOD = 998244353
val SZ = 1 shl 18
val INF = (1e18).toLong()

fun add(a: Int, b: Int) = (a + b) % MOD
fun sub(a: Int, b: Int) = (a - b + MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong() * b) % MOD).toInt()

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextInts() = next().split(" ").map { it.toInt() }
fun nextLongs() = next().split(" ").map { it.toLong() }

fun fdiv(a: Int, b: Int) : Int {
    if (a % b == 0 || a > 0) return a/b
    return a/b-1
}

fun cdiv(a: Int, b: Int) : Int {
    if (a % b == 0 || a < 0) return a/b
    return a/b+1
}

val xd = arrayOf(1,0,-1,0)
val yd = arrayOf(0,1,0,-1)

fun area(x0: Int, x1: Int, y0: Int, y1: Int) : Long {
    return (x1-x0+1).toLong()*(y1-y0+1)
}

var y = 1
val nex = IntArray(MX)
val pre = IntArray(MX)

fun tri(DP: HashMap<Int,Long>, a: Int, A: Long) {
    val v = DP.getOrDefault(a,INF)
    if (A < v) DP[a] = A
}

fun upd(DP: HashMap<Int,Long>, a: Int, A: Long) {
    if (pre[a] != -MOD) {
        tri(DP,pre[a],A+a-pre[a])
    }
    if (nex[a] != MOD) {
        tri(DP,nex[a],A+nex[a]-a)
    }
}

fun solve() {
    val (n,m,k,q) = nextInts()
    val todo = Array<ArrayList<Int>>(n+1,{ArrayList<Int>()})
    var mx = 1
    todo[1].add(1)
    for (i in 1..k) {
        val (r,c) = nextInts()
        todo[r].add(c)
        mx = maxOf(mx,r)
    }
    val b = nextInts()
    // println(b)
    for (i in 0..m+1) {
        nex[i] = MOD
        pre[i] = -MOD
    }
    for (i in b) {
        nex[i] = i
        pre[i] = i
    }
    for (i in m downTo 1) if (nex[i] == MOD) nex[i] = nex[i+1]
    for (i in 1..m) if (pre[i] == -MOD) pre[i] = pre[i-1]
    // println(pre[2])
    var dp = HashMap<Int,Long>()
    dp[1] = 0
    // println(nex[1])
    for (i in 1..n) if (todo[i].size > 0) {
        y = i
        todo[i].sort()
        val a = todo[i][0]
        val b = todo[i][todo[i].size-1]
        var DP = HashMap<Int,Long>()
        var A = INF
        var B = INF
        // println("HUH")
        // println(dp)
        for ((c,d) in dp) {
            A = minOf(A,d+Math.abs(b-c))
            B = minOf(B,d+Math.abs(a-c))
        }
        A += b-a
        B += b-a
        // println("HA $i $a $b $A $B")
        if (mx == i) {
            println(minOf(A,B)+y-1)
        } else {
            upd(DP,a,A)
            upd(DP,b,B)
            dp = DP
            // println(dp)
        }
        // println("?? $dp")
    }
}

fun main(args: Array<String>) {
    val t = 1
    for (i in 0..t-1) {
        solve()
    }
}