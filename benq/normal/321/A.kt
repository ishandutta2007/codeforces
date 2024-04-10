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

fun solve() {
    val (a,b) = nextInts()
    val s = next()
    var (x,y) = arrayOf(0,0)
    for (c in s) {
        if (c == 'U') {
            y ++
        }
        if (c == 'D') {
            y --
        }
        if (c == 'L') {
            x --
        }
        if (c == 'R') {
            x ++
        }
    }
    var (X,Y) = arrayOf(0,0)
    for (c in s) {
        var (difx,dify) = arrayOf(a-X,b-Y)
        if (isMul(difx,dify,x,y)) {
            println("Yes")
            System.exit(0)
        }
        if (c == 'U') {
            Y ++
        }
        if (c == 'D') {
            Y --
        }
        if (c == 'L') {
            X --
        }
        if (c == 'R') {
            X ++
        }
    }
    println("No")
}

fun main(args: Array<String>) {
    solve()
}