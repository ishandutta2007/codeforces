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

var n = 0
val adj = Array<ArrayList<Boolean>>(501,{ArrayList<Boolean>()})
val adj0 = Array<BooleanArray> (16,{BooleanArray(16)})
val adj1 = Array<BooleanArray> (16,{BooleanArray(16)})
val group = IntArray(501)
val label = IntArray(16)
val rlabel = IntArray(16)
var co = 0

fun ins(x: Int, i: Int) {
    label[x] = i
    rlabel[i] = x
}

fun del(x: Int, i: Int) {
    label[x] = -1
    rlabel[i] = -1
}

fun dfs(x: Int) {
    if (x == co) {
        for (i in 1..n) {
            print(label[group[i]])
            print(' ')
        }
        System.exit(0)
    }
    for (i in 0..15) if (rlabel[i] == -1) {
        ins(x,i)
        var bad = false
        for (y in 0..x-1) if (adj0[y][x] != adj1[label[y]][label[x]]) {
            bad = true
            break
        }
        if (!bad) dfs(x+1)
        del(x,i)
    }
}

fun solve() {
    // write code here
    val (_n,m) = nextInts()
    n = _n
    for (i in 1..n) {
        adj[i] = ArrayList<Boolean>()
        for (j in 0..n) adj[i].add(false)
    }
    for (i in 1..m) {
        val (u,v) = nextInts()
        adj[u][v] = true
        adj[v][u] = true
    }
    val H = HashMap<ArrayList<Boolean>,ArrayList<Int>>()
    for (i in 1..n) {
        val a = H.getOrPut(adj[i],{ArrayList<Int>()})
        a.add(i)
    }
    for ((x,y) in H) {
        for (i in y) group[i] = co
        co ++
    }
    for (i in 1..n) for (j in 1..n)
        if (adj[i][j]) {
            adj0[group[i]][group[j]] = true
        }
    for (i in 0..15) {
        label[i] = -1
        rlabel[i] = -1
        for (j in 0..3) adj1[i][i.xor(1 shl j)] = true
    }
    ins(0,0)
    dfs(1)
}

fun main(args: Array<String>) {
    val t = 1 // # of test cases
    for (i in 1..t) {
        solve()
    }
    print(out)
}