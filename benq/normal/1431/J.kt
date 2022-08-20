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
    val a = io.longs(n)
    var xo = 0L
    fun getBit(l: Long, ind: Int): Long {
        return (l shr ind) and 1L
    }
    fun getBit(l: Int, ind: Int): Int {
        return (l shr ind) and 1
    }
    fun bits(ind: Int): Long = (1L shl ind)-1
    val intervals = ArrayList<Pair<Int,Pair<Long,Long>>>()
    fun interval(l: Long, r: Long) {
        if (l == r) {
            xo = xo xor l
            return
        }
        var ind = 59
        while (getBit(l,ind) == getBit(r,ind)) ind --
        val base = (l xor (l and bits(ind+1)))
        xo = xo xor base
        intervals.add(Pair<Int,Pair<Long,Long>>(ind,Pair<Long,Long>(l xor base, r xor base)))
    }
    for (i in 0..n-1) interval(a[i],a[i])
    for (i in 0..n-2) interval(a[i],a[i+1])
//    println(xo)
//    println(intervals)
    fun red(a: Long): Int = (a%MOD).toInt()
//    fun mulMod(a: Long, b: Long): Int = mul((a%MOD).toInt(),(b%MOD).toInt())
    var ans = 0
    val ipo = IntArray(60){1}
    ipo[1] = (MOD+1)/2
    for (i in 2..59) ipo[i] = mul(ipo[i-1],ipo[1])
//    println("xo ${xo}")
//    println("intervals ${intervals}")
    for (mask in 0 until (1 shl intervals.size)) {
        var newXo = xo
        val oops = ArrayList<Long>()
        for (j in 0 until intervals.size) {
            if (getBit(mask,j) == 1) {
                val lo = (1L shl intervals[j].first)
                newXo = newXo xor lo
                oops.add(intervals[j].second.second-lo+1)
            } else {
                val hi = (1L shl intervals[j].first)-1
                newXo = newXo xor hi
                oops.add(hi-intervals[j].second.first+1)
            }
        }
//        println(newXo)
//        println(mask)
//        println(oops)
        for (bit in 59 downTo -1) {
            if (bit == -1) {
                ans = add(ans,1)
                break
            }
            fun adv(done: IntArray, l: Long, r: Long): IntArray {
                val tran = arrayOf(red(l),red(r))
                val x = add(mul(done[0],tran[0]),mul(done[1],tran[1]))
                val y = add(mul(done[0],tran[1]),mul(done[1],tran[0]))
                return intArrayOf(x,y)
            }
            var done = IntArray(2){0}
            var actual = getBit(newXo,bit).toInt()
            done[actual] = 1
            var nex = 1
            for (i in 0 until oops.size) {
                // dp[one pos][chose left]
                if (oops[i] > (1L shl bit)) {
                    oops[i] -= (1L shl bit)
                    done = adv(done,(1L shl bit),oops[i]) // place 0 or 1
                    actual = actual xor 1
                } else {
                    val l = red(oops[i])
                    done[0] = mul(done[0],l)
                    done[1] = mul(done[1],l)
                }
                nex = mul(nex,red(oops[i]))
            }
            if (actual == 1) {
                ans = add(ans,mul(done[0],ipo[bit]))
                break
            } else {
                ans = add(ans,mul(sub(done[0],nex),ipo[bit]))
            }
        }
//        println(ans)
//        println()
    }
    println(ans)
}

fun main() {
//    val t = io.int()
    val t = 1
    repeat(t) { solve() }
    io.close()
}