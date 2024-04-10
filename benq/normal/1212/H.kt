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

var n = 0
var k = 0

val adj = Array(401,{ArrayList<Pair<Int,Int>>()})
val dp = Array(401,{ArrayList<Int>()})
val pre = Array(401,{ArrayList<Int>()})
val par = Array<Pair<Int,Int>>(401,{Pair<Int,Int>(0,0)})

fun comb(a: ArrayList<Int>, b: ArrayList<Int>): ArrayList<Int> {
    val res = ArrayList<Int>()
    val sz = a.size+b.size-1
    for (i in 0..sz-1) res.add(MOD)
    res[0] = 1
    // a[1] ++
    // a[i]+b[j], i > 0, j > 0
    for (i in 1..a.size-1)
        for (j in 0..b.size-1)
            res[i+j] = minOf(res[i+j],a[i]+b[j])
    return res
}

fun dfs(x: Int) {
    dp[x] = arrayListOf(1,0)
    for (t in adj[x]) if (t.first != par[x].first) {
        par[t.first] = Pair(x,t.second)
        dfs(t.first)
        pre[t.first] = ArrayList(dp[x])
        dp[x] = comb(pre[t.first],dp[t.first])
    }
    // println("$x ${dp[x]}")
}

val ans = ArrayList<Int>()

fun genAns(x: Int, _lef: Int) {
    var lef = _lef
    if (lef == 0) {
        ans.add(par[x].second)
        return
    }
    adj[x].reverse()
    for (t in adj[x]) if (t.first != par[x].first) {
        if (lef == 1) {
            ans.add(t.second)
        } else {
            var done = false
            for (i in 1..pre[t.first].size-1) {
                for (j in 0..dp[t.first].size-1)
                    if (i+j == lef && pre[t.first][i]+dp[t.first][j] == dp[x][lef]) {
                        done = true
                        lef = i
                        genAns(t.first,j)
                        break
                    }
                if (done) break
            }
            assert(done)
        }
        dp[x] = ArrayList(pre[t.first])
    }
    assert(lef == 1)
}


fun finish(x: Int) {
    if (x != 1) {
        ans.add(par[x].second)
    }
    genAns(x,k)
    println(ans.size)
    for (t in ans) print("$t ")
    System.exit(0)
}

fun solve() {
    val (N,K) = nextInts()
    n = N
    k = K
    for (i in 1..n-1) {
        val (x,y) = nextInts()
        adj[x].add(Pair(y,i))
        adj[y].add(Pair(x,i))
    }
    dfs(1)
    var res = MOD
    for (i in 1..N) if (dp[i].size > k) {
        var v = dp[i][k]
        if (i != 1) v ++
        res = minOf(res,v)
    }
    for (i in 1..N) if (dp[i].size > k) {
        var v = dp[i][k]
        if (i != 1) v ++
        if (res == v) finish(i)
    }
    // println(res)
}

fun main(args: Array<String>) {
    val T = 1
    for (i in 1..T) solve()
}