/**
 * Description: Kotlin tips for dummies
 * Source: own
 */

/* sorting
 * 1 (ok)
    val a = nextLongs().sorted() // a is mutable list
 * 2 (ok)
    val a = arrayListOf<Long>() // or ArrayList<Long>()
    a.addAll(nextLongs())
    a.sort()
 *.3 (ok)
    val A = nextLongs()
    val a = Array<Long>(n,{0})
    for (i in 0..n-1) a[i] = A[i]
    a.sort()
 * 4 (ok)
    val a = ArrayList(nextLongs())
    a.sort()
 * 5 (NOT ok)
    val a = LongArray(N) // or nextLongs().toLongArray()
    Arrays.sort(a)
 */
/* 2D array
 * val ori = Array(n, {IntArray(n)})
 * val ori = arrayOf(
    intArrayOf(8, 9, 1, 13),
    intArrayOf(3, 12, 7, 5),
    intArrayOf(0, 2, 4, 11),
    intArrayOf(6, 10, 15, 14)
    )
 */
/* printing variables:
 * println("${l+1} and $r")
 * print d to 8 decimal places: String.format("%.8g%n", d)
 * try to print one stringbuilder instead of multiple prints
 */
/* comparing pairs
    val pq = PriorityQueue<Pair<Long,Int>>({x,y -> x.first.compareTo(y.first)})
    val pq = PriorityQueue<Pair<Long,Int>>(compareBy {it.first})
    val A = arrayListOf(Pair(1,3),Pair(3,2),Pair(2,3))
    val B = A.sortedWith(Comparator<Pair<Int,Int>>{x,y -> x.first.compareTo(y.first)})
    sortBy
 */
/* hashmap
    val h = HashMap<String,Int>()
    for (i in 0..n-2) {
        val w = s.substring(i,i+2)
        val c = h.getOrElse(w){0}
        h.put(w,c+1)
    }
 */
/* basically switch, can be used as expression
    when (x) {
        0,1 -> print("x <= 1")
        2 -> print("x == 2")
        else -> { // Note the block
            print("x is neither 1 nor 2")
        }
    }
*/
// swap : a = b.also { b = a }
// arraylist remove element at index: removeAt, not remove ...
// lower bound: use .binarySearch()

import java.util.*
// import kotlin.math.*

val MOD = 1000000007
val SZ = 1 shl 18
val INF = (1e18).toLong()

fun add(a: Int, b: Int) = (a+b) % MOD // from tourist :o
fun sub(a: Int, b: Int) = (a-b+MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong() * b) % MOD).toInt()

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextInts() = next().split(" ").map { it.toInt() }
fun nextLongs() = next().split(" ").map { it.toLong() }

val out = StringBuilder()
fun YN(b: Boolean):String { return if (b) "YES" else "NO"  }

fun gcd(a: Int, b: Int): Int {
    return if (a == 0) b else gcd(b%a,a)
}

fun isMul(a: Int, b: Int, c: Int, d: Int): Boolean {
    if (a == 0 && b == 0) return true
    if (c == 0 && d == 0) return false
    if (a.toLong()*d != b.toLong()*c) return false
    if (c != 0) {
        if (a%c != 0 || a/c < 0) return false
    } else {
        if (b%d != 0 || b/d < 0) return false
    }
    return true
}

var cnt = 0
var vis = BooleanArray(1,{false})
var adj = Array<ArrayList<Int>>(1,{ArrayList<Int>()})

fun dfs(x: Int) {
    if (vis[x]) return
    vis[x] = true
    cnt ++
    for (i in adj[x]) dfs(i)
}

fun po(a: Int, b: Int): Int {
    if (b == 0) return 1
    var res: Int = po(mul(a,a),b/2)
    if ((b and 1) == 1) res = mul(res,a)
    return res
}

fun solve() {
    val (n,k) = nextInts()
    adj = Array<ArrayList<Int>>(n+1,{ArrayList<Int>()})
    vis = BooleanArray(n+1,{false})
    for (i in 1..n-1) {
        val (u,v,x) = nextInts()
        if (x == 0) {
            adj[u].add(v)
            adj[v].add(u)
        }
    }
    var ans = po(n,k)
    for (i in 1..n) if (!vis[i]) {
        cnt = 0
        dfs(i)
        ans -= po(cnt,k)
        ans = (ans%MOD+MOD)%MOD
    }
    println(ans)
}

fun main(args: Array<String>) {
    solve()
}