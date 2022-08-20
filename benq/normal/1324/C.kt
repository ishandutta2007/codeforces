/**
 * Description: Kotlin tips for dummies
 * Source: https://codeforces.com/blog/entry/71089, own
 */

/// episode 1: https://codeforces.com/contest/1170
/// episode 2: https://codeforces.com/contest/1211
/// episode 3: https://codeforces.com/contest/1297
/* sorting
 * 1 (ok)
	val a = nextLongs().sorted() // a is mutable list
 * 2 (ok)
	val a = arrayListOf<Long>() // or ArrayList<Long>()
	a.addAll(nextLongs())
	a.sort()
 * 3 (ok)
	val A = nextLongs()
	val a = Array<Long>(n,{0})
	for (i in 0..n-1) a[i] = A[i]
	a.sort()
 * 4 (ok)
	val a = ArrayList(nextLongs())
	a.sort()
 * 5 (NOT ok, quicksort)
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
										~ (compareBy {it.first})
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

import java.io.*
import java.util.*
/*import java.math.*
import kotlin.math.*
import kotlin.random.*
import kotlin.collections.*
import kotlin.io.**/

/** IO code start */
//@JvmField val INPUT = File("input.txt").inputStream()
//@JvmField val OUTPUT = File("output.txt").outputStream()
@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out
@JvmField val _reader = INPUT.bufferedReader()
@JvmField val _writer = PrintWriter(OUTPUT, false)

fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not())
        _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { readInt() }
fun readDoubles(n: Int) = List(n) { readDouble() }
fun readLongs(n: Int) = List(n) { readLong() }

val MOD = 1000000007
val INF = (1e18).toLong()
val SZ = 1 shl 17

fun add(a: Int, b: Int) = (a+b) % MOD // from tourist :o
fun sub(a: Int, b: Int) = (a-b+MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong()*b)%MOD).toInt()
fun gcd(a: Int, b: Int) : Int = if (b == 0) a else gcd(b,a%b)
fun YN(b: Boolean) : String { return if (b) "YES" else "NO"  }

class BIT() {
    val v = LongArray(SZ)
    fun upd(_a: Int, b: Long) {
        var a = _a
        while (a < SZ) {
            v[a] += b
            a += (a and -a)
        }
    }
    fun query(_a: Int): Long {
        var a = _a
        var ans: Long = 0
        while (a > 0) {
            ans += v[a]
            a -= (a and -a)
        }
        return ans
    }
}

fun solve() {
    val s = 'R'+readLn()+'R'
    var lst = 0
    var ans = 0
    for (i in 1..s.length-1) {
        if (s[i] == 'R') {
            ans = maxOf(ans,i-lst)
            lst = i
        }
    }
    println(ans)
}
fun main() {
    val t = readInt()
    for (i in 1..t) solve()
}