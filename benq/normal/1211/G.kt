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

val adj = Array<ArrayList<Int>>(MX,{ArrayList<Int>()})
val depth = IntArray(MX)
val par = IntArray(MX)

fun dfs(x: Int) {
    for (i in adj[x]) if (i != par[x]) {
        par[i] = x
        depth[i] = depth[x]+1
        dfs(i)
    }
}

fun maxBad(n: Int, bad: ArrayList<Int>): Int {
    var maxDepth = -1
    var cool = -1
    for (i in bad) maxDepth = maxOf(maxDepth,depth[i])
    for (i in bad) if (depth[i] == maxDepth) cool = i
    return cool
}

fun gen(i: Int) {
    depth[i] = 0
    par[i] = 0
    dfs(i)
}

fun check(n: Int, c: ArrayList<Int>, d: ArrayList<Int>, path: ArrayList<Int>): Boolean {
    var C = ArrayList(c)
    for (i in 0..path.size-2) {
        C[path[i]] = C[path[i+1]]
    }
    C[path[path.size-1]] = c[path[0]]
    /*println(path)
    println(C)
    println(d)
    println(path[0])
    println(c[path[0]])*/
    for (i in 1..n) if (C[i] != d[i]) return false

    out.append("Yes\n")
    out.append(path.size)
    out.append("\n")
    for (i in path) {
        out.append(i)
        out.append(" ")
    }
    out.append("\n")
    return true
}

fun solve() {
    // write code here
    val n = nextInt()
    var c = ArrayList(nextInts())
    var d = ArrayList(nextInts())
    c.add(0,0)
    d.add(0,0)

    for (i in 1..n) adj[i].clear()
    for (i in 1..n-1) {
        val (x,y) = nextInts()
        adj[x].add(y)
        adj[y].add(x)
    }
    val bad = ArrayList<Int>()
    for (i in 1..n) if (d[i] != c[i]) bad.add(i)
    if (bad.size == 0) {
        out.append("Yes\n")
        out.append("0\n")
        return
    }
    gen(1)
    // println(bad)
    // for (i in bad) println("$i ${depth[i]}")
    var x = maxBad(n,bad)
    gen(x)
    var y = maxBad(n,bad)
    // println(x)
    // println(y)
    val path = ArrayList<Int>()
    while (y != x) {
        path.add(y)
        y = par[y]
    }
    path.add(y)
    if (check(n,c,d,path)) return
    path.reverse()
    if (check(n,c,d,path)) return
    out.append("No\n")
}

fun main(args: Array<String>) {
    val t = nextInt() // # of test cases
    for (i in 1..t) {
        solve()
    }
    print(out)
}