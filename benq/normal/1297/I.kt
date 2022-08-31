/**
 * Description: Kotlin tips for dummies
 * Source: https://codeforces.com/blog/entry/71089, own
 */

// episode 1: https://codeforces.com/contest/1170
// episode 2: https://codeforces.com/contest/1211
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

@file:Suppress("NOTHING_TO_INLINE", "EXPERIMENTAL_FEATURE_WARNING", "OVERRIDE_BY_INLINE")

import java.io.PrintWriter
import java.util.StringTokenizer
import java.util.TreeMap
import java.util.PriorityQueue
import kotlin.math.*
import kotlin.random.*
import kotlin.collections.sort as _sort
import kotlin.collections.sortDescending as _sortDescending
import kotlin.io.println as iprintln

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

/** @author Spheniscine */
fun main() { _writer.solve(); _writer.flush() }
fun quo(a: Int, b: Int): Int {
    if (a%b < b/2) return a/b
    return a/b+1
}

val SZ = 1 shl 17
val h = IntArray(100000)
val use = BooleanArray(100000,{false})
val all = Array<ArrayList<Int>>(2*SZ,{ArrayList<Int>()})
val par = IntArray(2*SZ,{-1})
var cans = 0
val lef = IntArray(100000)
val rig = IntArray(100000)

fun bet(a: Int, b: Int) : Int {
    if (minOf(a,b) == -1) return maxOf(a,b)
    if (h[a] > h[b]) return a
    return b
}

fun pull(ind: Int, L: Int, R: Int) {
    par[ind] = -1
    if (all[ind].size > 0) par[ind] = all[ind].last()
    if (L != R) {
        par[ind] = bet(par[ind],bet(par[2*ind],par[2*ind+1]))
    }
}

fun mx(lo: Int, hi: Int, ind: Int, L: Int, R: Int): Int {
    if (R < lo || hi < L) return -1
    var ret = -1
    if (all[ind].size > 0) ret = all[ind].last()
    if (lo <= L && R <= hi) {
        ret = bet(ret,par[ind])
        return ret
    }
    val M = (L+R)/2
    ret = bet(ret,mx(lo,hi,2*ind,L,M))
    ret = bet(ret,mx(lo,hi,2*ind+1,M+1,R))
    return ret
}

fun PrintWriter.rem(lo: Int, hi: Int, nex: Int, ind: Int, L: Int, R: Int) {
    // println("AH ${lo} ${hi} ${nex} ${ind} ${L} ${R}")
    if (R < lo || hi < L) return
    if (lo <= L && R <= hi) {
        assert(all[ind][all[ind].size-1] == nex)
        //println("AA")
        //println(all[ind])
        all[ind].removeAt(all[ind].size-1)
        //println("BB")
        //println(all[ind])
    } else {
        val M = (L+R)/2
        rem(lo,hi,nex,2*ind,L,M)
        rem(lo,hi,nex,2*ind+1,M+1,R)
    }
    pull(ind,L,R)
    /*if (par[ind] == nex) {
        println("WUT")
        println(ind)
        println(all[ind])
        println(par[ind])
        println(par[2*ind])
        println(par[2*ind+1])
    }*/
    // println("OH ${ind} ${par[ind]} ${nex}")
}

fun PrintWriter.ins(lo: Int, hi: Int, nex: Int, ind: Int, L: Int, R: Int) {
    // println("AH ${lo} ${hi} ${nex} ${ind} ${L} ${R}")
    if (R < lo || hi < L) return
    if (lo <= L && R <= hi) {
        all[ind].add(nex)
    } else {
        val M = (L+R)/2
        ins(lo,hi,nex,2*ind,L,M)
        ins(lo,hi,nex,2*ind+1,M+1,R)
    }
    pull(ind,L,R)
}

fun lhei(l: Int): Int {
    val b = mx(l,l,1,0,SZ-1)
    if (b != -1 && lef[b] < l) return h[b]
    return -1
}

fun rhei(r: Int): Int {
    val b = mx(r,r,1,0,SZ-1)
    if (b != -1 && rig[b] > r) return h[b]
    return -1
}

fun PrintWriter.solve() {
    val (n,d) = readInts(2)
    for (i in 0..n-1) {
        val (l,r) = readInts(2)
        lef[i] = l
        rig[i] = r
        cans ++
        var cnt = 10
        while (true) {
            val z = mx(l,r,1,0,SZ-1)
            /*print("PAR ")
            println(par[1])
            println("${i} ${z} ${maxOf(lhei(l),rhei(r))}")*/
            cnt ++
            //if (cnt > 5) return
            if (z == -1 || maxOf(lhei(l),rhei(r)) == h[z]) {
                if (z == -1) h[i] = 1
                else h[i] = h[z]+1
                ins(l,r,i,1,0,SZ-1)
                break
            } else {
                /*println(par[1])
                println(z)
                println(lef[z])
                println(rig[z])*/
                rem(lef[z],rig[z],z,1,0,SZ-1)
                cans --
                /*println(par[1])
                println(par[2])
                println(par[3])
                return*/
            }
        }
        println(cans)
    }
}

/** IO code start */
//@JvmField val INPUT = File("input.txt").inputStream()
//@JvmField val OUTPUT = File("output.txt").outputStream()
@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out

@JvmField val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }

@JvmField val _writer = PrintWriter(OUTPUT, false)

/** shuffles and sort overrides to avoid quicksort attacks */
private inline fun <T> _shuffle(rnd: Random, get: (Int) -> T, set: (Int, T) -> Unit, size: Int) {
    // Fisher-Yates shuffle algorithm
    for (i in size - 1 downTo 1) {
        val j = rnd.nextInt(i + 1)
        val temp = get(i)
        set(i, get(j))
        set(j, temp)
    }
}

@JvmField var _random: Random? = null
val random get() = _random ?: Random(0x564E235C123 * System.nanoTime()).also { _random = it }

fun IntArray.shuffle(rnd: Random = random) = _shuffle(rnd, ::get, ::set, size)
fun IntArray.sort() { shuffle(); _sort() }
fun IntArray.sortDescending() { shuffle(); _sortDescending() }

fun LongArray.shuffle(rnd: Random = random) = _shuffle(rnd, ::get, ::set, size)
fun LongArray.sort() { shuffle(); _sort() }
fun LongArray.sortDescending() { shuffle(); _sortDescending() }

fun DoubleArray.shuffle(rnd: Random = random) = _shuffle(rnd, ::get, ::set, size)
fun DoubleArray.sort() { shuffle(); _sort() }
fun DoubleArray.sortDescending() { shuffle(); _sortDescending() }

fun CharArray.shuffle(rnd: Random = random) = _shuffle(rnd, ::get, ::set, size)
inline fun CharArray.sort() { _sort() }
inline fun CharArray.sortDescending() { _sortDescending() }

inline fun <T: Comparable<T>> Array<out T>.sort() = _sort()
inline fun <T: Comparable<T>> Array<out T>.sortDescending() = _sortDescending()
inline fun <T: Comparable<T>> MutableList<out T>.sort() = _sort()
inline fun <T: Comparable<T>> MutableList<out T>.sortDescending() = _sortDescending()

fun `please stop removing these imports IntelliJ`() {
    iprintln(max(1, 2))
}

val MOD = 1000000007
val INF = (1e18).toLong()

fun add(a: Int, b: Int) = (a+b) % MOD // from tourist :o
fun sub(a: Int, b: Int) = (a-b+MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong() * b) % MOD).toInt()
fun YN(b: Boolean):String { return if (b) "YES" else "NO"  }