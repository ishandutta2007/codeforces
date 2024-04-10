/**
 * Description: Kotlin tips for dummies
 * Source:
    * https://codeforces.com/blog/entry/71089
    * Kotlin Reference
    * https://kotlinlang.org/docs/tutorials/competitive-programming.html
 */

/// episode 1: https://codeforces.com/contest/1170
/// episode 2: https://codeforces.com/contest/1211
/// episode 3: https://codeforces.com/contest/1297

import java.io.*
import java.util.*
import kotlin.system.exitProcess

// @JvmField val INPUT = File("input.txt").inputStream()
// @JvmField val OUTPUT = File("output.txt").outputStream()

/// https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.jvm/-jvm-field/

class Kattio: PrintWriter {
    @JvmField val r: BufferedReader
    @JvmField var st = StringTokenizer("")
    constructor(): this(System.`in`,System.out) {}
    constructor(i: InputStream, o: OutputStream): super(o,false) { r = i.bufferedReader() }
    fun rLine(): String? = r.readLine()

    fun read(): String { // if no input left returns empty string
        while (st.hasMoreTokens().not()) st =
            StringTokenizer(rLine() ?: return "", " ")
        return st.nextToken()
    }
    fun strs(n: Int) = List(n){read()}
    fun ln() = rLine()!!
    fun lns(n: Int) = List(n){ln()}
    fun int() = read().toInt()
    fun ints(n: Int) = List(n){int()}
    fun db() = read().toDouble()
    fun rDbs(n: Int) = List(n){db()}
    fun long() = read().toLong()
    fun longs(n: Int) = List(n){long()}
}

val io = Kattio()
//const val MOD = 1000000007
const val MOD = 998244353
const val INF = (1e18).toLong()
const val SZ = 1 shl 17

fun YN(b: Boolean) : String { return if (b) "YES" else "NO"  }
fun add(a: Int, b: Int) = (a+b) % MOD // from tourist :o
fun sub(a: Int, b: Int) = (a-b+MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong()*b)%MOD).toInt()
fun gcd(a: Int, b: Int) : Int = if (b == 0) a else gcd(b,a%b)

fun example() {
    println(String.format("%.8f", 5.25)) // print to 8 decimals
    val arr2D = Array<IntArray>(5,{IntArray(5,{5})})
    var (x,y) = arrayOf(3,2) // or rInts(2)
    when (x) { //  switch, can be used as expression
        0,1 -> println("x <= 1")
        2 -> println("x == 2") // Note the block
        else -> { println("x is neither 1 nor 2") }
    }
    x = y.also { y = x } // swap x and y
    println("${maxOf(x+2,y)}") // (x,y)=(4,3) -> 4
    val h = HashMap<String,Int>()
    val s = "ababa"
    for (i in 0..s.length-2) {
        val w = s.substring(i,i+2)
        val c = h.getOrElse(w,{0})
        h[w] = c+1
    }
    for ((a,b) in h) println("${a} ${b}") // key,value
    val pq = PriorityQueue<Pair<Long,Int>>(){x,y ->
        x.first.compareTo(y.first)} // or compareBy{it.first}
    val A = arrayListOf(Pair(1,3),Pair(3,2),Pair(2,3))
    val B = A.sortedWith(Comparator<Pair<Int,Int>>{x,y ->
        x.first.compareTo(y.first)}) // or sortBy{it.first}
    val list = arrayListOf('a','b','c','d','e')
    println(list.binarySearch('d')) // 3
    list.remove('d')
    val actualInsertPoint = -(list.binarySearch('d')+1) // 3
    list.add(actualInsertPoint, 'd') // [a,b,c,d,e]
    list.removeAt(1) // remove at index -> [a,c,d,e]
}

fun solve() {
    val n = io.int()
    val a = io.ints(n)
    var lo = 0
    var hi = n
    val inds = List(n){i -> i}.sortedWith(Comparator<Int>{x,y -> a[x].compareTo(a[y])})
    fun construct(mid: Int): ArrayList<Int> {
        var sum = 1
        for (i in 0..mid-1) sum += a[inds[i]]
        val res = ArrayList<Int>()
        if (sum <= n) {
            var pos = mid
            for (i in 0..mid-1) {
                if (i == 0) {
                    for (j in 1..a[inds[i]]) {
                        res.add(inds[pos]+1)
                        pos += 1
                    }
                } else {
                    for (j in 1..a[inds[i]]-1) {
                        res.add(inds[pos]+1)
                        pos += 1
                    }
                }
                res.add(inds[i]+1)
            }
            while (pos < n) {
                res.add(inds[pos]+1)
                pos += 1
            }
        }
        return res
    }
    while (lo < hi) {
        val mid = (lo+hi+1)/2
        val x = construct(mid)
        if (x.size > 0) lo = mid
        else hi = mid-1
    }
//    println(lo)
    val v = construct(lo)
    for (i in v) {
        print(i)
        print(' ')
    }
    println()

//    val used = BooleanArray(n){false}
//    var cur = 0
//    repeat(n) {
//        var mn = n+1
//        for (i in 0 until n) if (!used[i]) {
//            mn = minOf(mn,a[i])
//        }
//        if (mn <= cur) {
//
//        } else {
//            for (i in 0 until n) if (!used[i]) mn = maxOf(mn,a[i])
//            cur ++
//        }
//        for (i in 0 until n) if (!used[i] && a[i] == mn) {
//            used[i] = true
//            print(i+1)
//            print(" ")
//            break
//        }
//    }
//    println()
}

fun main() {
    val t = io.int()
//    val t = 1
    repeat(t) { solve() }
    io.close()
}