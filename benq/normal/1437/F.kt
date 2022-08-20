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

fun needChange(sub: ArrayList<Int>): Int {
//    io.println(sub)
//    if (sub[0] > sub[sub.size-1]) {
//        io.println(-1)
//        io.close()
//        exitProcess(0)
//    }
    val bes = arrayListOf(sub[0])
    for (i in 1..sub.size-1) {
        // longest non-decreasing subsequence
        var lo = -1
        var hi = bes.size-1
        while (lo < hi) {
            var mid = (lo+hi+1)/2
            if (bes[mid] <= sub[i]) lo = mid
            else hi = mid-1
        }
        if (i == sub.size-1) {
            if (lo == -1) {
                io.println(-1)
                io.close()
                exitProcess(0)
            }
            return sub.size-(lo+2)
        }
        if (lo >= 0) {
            if (lo == bes.size-1) bes.add(0)
            bes[lo+1] = sub[i]
        }
    }
    return -1
}

fun solve() {
    val n = io.int()
    val a = io.ints(n).sorted()
    var dp = IntArray(n) {1}
    for (num in 1..n-1) {
        val DP = IntArray(n)
        val cum = IntArray(n)
        var j = 0
        var k = -1
        for (i in 0..n-1) if (dp[i] != 0) {
            while (2*a[k+1] <= a[i]) k ++
            assert(k+2 >= num);
            // did num
            // 1+(# <= a[i]/2) available
            DP[i] = add(DP[i],mul(dp[i],k+2-num))
            while (j < n && a[j] < 2*a[i]) j ++
            if (j < n) cum[j] = add(cum[j],dp[i])
        }
//        for (j in 0..n-1) {
//            print("${cum[j]} ")
//        }
//        println()
//        for (j in 0..n-1) {
//            print("${DP[j]} ")
//        }
//        println()
        for (j in 1 until n) {
            cum[j] = add(cum[j],cum[j-1])
            DP[j] = add(DP[j],cum[j])
        }
        dp = DP
    }
    var ans = 0
    for (i in dp) ans = add(ans,i)
    println(ans)

}

fun main() {
//    val t = io.int()
    val t = 1
    repeat(t) { solve() }
    io.close()
}