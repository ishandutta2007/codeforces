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

val adj = Array<ArrayList<Pair<Int,Int>>>(MX,{ArrayList<Pair<Int,Int>>()})
val par = IntArray(MX)
val dp = IntArray(MX)
var mid = 0
var bad = false
val arr = Array<ArrayList<Int>>(MX,{ArrayList<Int>()})
val ARR = Array<ArrayList<Int>>(MX,{ArrayList<Int>()})

var ans = IntArray(0)

fun adv(x: ArrayList<Int>, y: Int) {
    for (i in 1..y) {
        x.add(0)
    }
    for (i in x.size-y-1 downTo 0) if (x[i] == 1) x[i+y] = 1
}

fun dfs(x: Int) {
    if (bad) return
    arr[x] = arrayListOf(1)
    for (i in adj[x]) {
        val y = i.first
        if (y != par[x]) {
            par[y] = x
            dfs(y)
            if (bad) return

            ARR[y] = arr[x]
            arr[x] = ArrayList(ARR[y])
            adv(arr[x],dp[y]+1)
        }
    }
    // println(x)
    // println(arr[x])
    for (i in 0..arr[x].size-1) if (arr[x][i] == 1 && i <= mid && arr[x].size-1-i <= mid) {
        dp[x] = i
        return
    }
    dp[x] = -1
    bad = true
}

fun ok(): Boolean {
    bad = false
    dfs(1)
    return !bad
}

var cnt = 0

fun construct(x: Int, lst: Int) {
    adj[x].reverse()
    var sz = dp[x]
    val LST = ++cnt

    for (i in adj[x]) {
        val y = i.first
        if (y != par[x]) {
            if (sz >= dp[y]+1 && ARR[y][sz-dp[y]-1] == 1) {
                ans[i.second] = lst
                construct(y,lst)
                sz -= dp[y]+1
            } else {
                assert(ARR[y][sz] == 1)
                ans[i.second] = LST
                construct(y,LST)
            }
        }
    }
}

fun solve() {
    // write code here
    val n = nextInt()
    for (i in 1..n) adj[i].clear()
    for (i in 0..n-2) {
        val (x,y) = nextInts()
        adj[x].add(Pair(y,i))
        adj[y].add(Pair(x,i))
    }
    var lo = 1
    var hi = n-1
    mid = 1
    // println(ok())
    // for (i in 1..n) println("$i ${dp[i]}")
    // System.exit(0)
    while (lo < hi) {
        mid = (lo+hi)/2
        if (ok()) hi = mid
        else lo = mid+1
    }
    mid = lo
    ok()
    ans = IntArray(n-1)
    construct(1,++cnt)
    println(mid)
    for (i in ans) {
        print("$i ")
    }
    println()
}

fun main(args: Array<String>) {
    val t = nextInt() // # of test cases
    for (i in 1..t) {
        solve()
    }
    print(out)
}