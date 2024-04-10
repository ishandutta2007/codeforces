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

val MX = 1000005
val MOD = 998244353
val SZ = 1 shl 19
val INF = (1e18).toLong()

fun add(a: Int, b: Int) = (a + b) % MOD
fun sub(a: Int, b: Int) = (a - b + MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong() * b) % MOD).toInt()

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextInts() = next().split(" ").map { it.toInt() }
fun nextLongs() = next().split(" ").map { it.toLong() }

fun solve(){
    val (n,m) = nextInts()
    val A = Array(n) { next() }
    // for (i in 0..n-1) println(A[i])
    var r0 = Array<BooleanArray>(n,{BooleanArray(m)})
    var r1 = Array<BooleanArray>(n,{BooleanArray(m)})
    r0[0][0] = true
    for (i in 0..n-1) for (j in 0..m-1) {
        if (A[i][j] == '#') r0[i][j] = false
        else if (r0[i][j]) {
            if (i+1 < n) r0[i+1][j] = true
            if (j+1 < m) r0[i][j+1] = true
        }
    }
    r1[n-1][m-1] = true
    for (i in n-1 downTo 0)  for (j in m-1 downTo 0) {
        if (A[i][j] == '#') r1[i][j] = false
        else if (r1[i][j]) {
            if (i-1 >= 0) r1[i-1][j] = true
            if (j-1 >= 0) r1[i][j-1] = true
        }
    }
    if (!r0[n-1][m-1]) {
        print(0)
        return
    }
    val mn = IntArray(n,{MOD})
    val mx = IntArray(n,{-MOD})
    for (i in 0..n-1) {
        for (j in 0..m-1) if (r0[i][j] && r1[i][j]) {
            mn[i] = minOf(mn[i],j)
            mx[i] = maxOf(mx[i],j)
        }
    }
    // println(mn[1])
    // println(mx[1])
    for (i in 0..n-1) for (j in 0..m-1) {
        if (i+j == 0) continue
        if (i+j == n-1+m-1) continue
        // println("$i $j")
        if ((i == 0 || mx[i-1] <= j) && (i == n-1 || mn[i+1] >= j)) {
            print(1)
            return
        }
    }
    print(2)
}

fun main(args: Array<String>) {
    val t = 1
    for (i in 0..t-1) {
        solve()
    }
}