// kotlin tips b/c I'm bad

/** useful links
 * https://kotlinlang.org/api/latest/jvm/stdlib/kotlin/-array/index.html
 * https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-list/index.html
 * https://kotlinlang.org/docs/reference/ranges.html
 */

/** valid ways to sort (avoid quicksort ...)
 * 1
    val a = nextLongs().sorted() // a is mutable list
 * 2
    val a = arrayListOf<Long>() // or ArrayList<Long>()
    a.addAll(nextLongs())
    a.sort()
 */

/** Bit shift
 * 1 shl 20
 */

/** 2D array
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

/** comparing pairs
    val pq = PriorityQueue<Pair<Long,Int>>({x,y -> x.first.compareTo(y.first)})
    val pq = PriorityQueue<Pair<Long,Int>>(compareBy {it.first})
 * https://alvinalexander.com/source-code-kotlin-sortedWith-syntax-lambda-examples
    val A = arrayListOf(Pair(1,3),Pair(3,2),Pair(2,3))
    val B = A.sortedWith(Comparator<Pair<Int,Int>>{x,y -> x.first.compareTo(y.first)})
    sortBy
 */

/** hashmap
 *  val h = HashMap<String,Int>()
    for (i in 0..n-2) {
        val w = s.substring(i,i+2)
        val c = h.getOrElse(w){0}
        h.put(w,c+1)
    }
 */

/** swap
 * https://kotlinlang.org/api/latest/jvm/stdlib/kotlin/also.html
 * a = b.also { b = a }
 */

// lower bound: use binary search
// https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/binary-search.html

// if / switch (when)
// https://kotlinlang.org/docs/reference/control-flow.html

// print d to 8 decimal places: String.format("%.8g%n", d)

// arraylist remove element at index: removeAt, not remove ...

import java.util.*

val MX = 200005
val MOD = 1000000007
val SZ = 1 shl 18
val INF = (1e18).toLong()

fun add(a: Int, b: Int) = (a + b) % MOD // from tourist :o
fun sub(a: Int, b: Int) = (a - b + MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong() * b) % MOD).toInt()

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextInts() = next().split(" ").map { it.toInt() }
fun nextLongs() = next().split(" ").map { it.toLong() }

val xd = arrayOf(1,0,-1,0)
val yd = arrayOf(0,1,0,-1)

val out = StringBuilder()

fun YN(b: Boolean) : String { return if (b) "YES" else "NO"  }

fun choose(r: ArrayList<Int>, x: Int): Int {
    for (i in 0..r.size-1) if (r[i] == x) return i+1
    return -1
}

val cnt = IntArray(1000001)
var ans = 0

fun check(ind: Int, a: Int, b: Int, k: Int) {
    val A = ArrayList<Int>()
    var i = ind
    while (i <= 1000000) {
        A.add(cnt[i])
        i *= k
    }
    var dp = ArrayList<Int>()
    for (i in 0..A[0]) dp.add(0)
    for (i in 0..A.size-2) {
        val DP = ArrayList<Int>()
        for (j in 0..A[i+1]) DP.add(0)
        var j = 0
        while (j*a <= A[i] && j*b <= A[i+1]) {
            DP[A[i+1]-j*b] = j+dp[j*a]
            j ++
        }
        dp = DP
        for (j in A[i+1]-1 downTo 0) dp[j] = maxOf(dp[j],dp[j+1])
    }
    /*if (dp[0] != 0) {
        println(ind)
        println(A)
        println(dp)
        println(dp[0])
    }*/
    ans += dp[0]
}

fun solve() {
    // write code here
    val (n,a,b,k) = nextInts()
    val r = nextInts()
    for (i in r) {
        cnt[i] ++
    }
    for (i in 1..1000000) if (i % k != 0) check(i,a,b,k)
    println(ans)
}

fun main(args: Array<String>) {
    val t = 1 // # of test cases
    for (i in 1..t) {
        solve()
    }
}