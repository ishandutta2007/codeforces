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

fun fdiv(a: Int, b: Int) : Int {
    if (a % b == 0 || a >= 0) return a/b
    return a/b-1
}

fun cdiv(a: Int, b: Int) : Int {
    if (a%b == 0) return a/b
    return a/b+1
}

fun solve() {
    val s = next()
    var lst = -1
    var ans = 0
    for (i in 0..s.length-1) {
        if (s[i] == '0') continue
        var x = 0
        for (j in i..s.length-1) {
            x = 2*x+(s[j]-'0')
            if (j-x+1 <= lst) break
            ans ++
        }
        lst = i
    }
    println(ans)
}

fun main(args: Array<String>) {
    val t = nextInt()
    for (i in 0..t-1) {
        solve()
    }
}