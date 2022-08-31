/**
 * Description: Kotlin tips for dummies
 * Source: https://codeforces.com/blog/entry/71089, Kotlin Reference
 */

/// episode 1: https://codeforces.com/contest/1170
/// episode 2: https://codeforces.com/contest/1211
/// episode 3: https://codeforces.com/contest/1297

import java.io.*
import java.util.* // do NOT use Arrays.sort()
import kotlin.math.abs

/// https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.jvm/-jvm-field/
// @JvmField val INPUT = File("input.txt").inputStream()
@JvmField val INPUT = System.`in`
// @JvmField val OUTPUT = File("output.txt").outputStream()
@JvmField val OUTPUT = System.out
@JvmField val _reader = INPUT.bufferedReader()
@JvmField val _writer = PrintWriter(OUTPUT, false) // if not interactive, faster to call _writer.flush() at end
fun rLine(): String? = _reader.readLine()
fun rLn() = rLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String { // if no input left returns empty string
    while (_tokenizer.hasMoreTokens().not()) _tokenizer =
        StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}
fun rInt() = read().toInt()
/// fun rDb() = read().toDouble()
fun rLong() = read().toLong()
fun rStrs(n: Int) = List(n,{read()})
fun rLns(n: Int) = List(n,{rLn()})
fun rInts(n: Int) = List(n,{rInt()})
/// fun rDbs(n: Int) = List(n,{rDb()})
fun rLongs(n: Int) = List(n,{rLong()})

val MOD = 1000000007
val INF = (1e18).toLong()
val SZ = 1 shl 17

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
        h.put(w,c+1)
    }
    for ((a,b) in h) println("${a} ${b}") // key,value
    val pq = PriorityQueue<Pair<Long,Int>>({x,y ->
        x.first.compareTo(y.first)}) // or compareBy{it.first}
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

//var dist = Array<IntArray>(15,{IntArray(15)})
//var sum = 0L
//var n = 0
//val mx = Array<LongArray>(15,{LongArray(226)}) // max after certain # of steps
//val po = Array<Array<LongArray>>(50,{Array<LongArray>(15,{LongArray(15)})})
//var a = IntArray(0)
//
//fun gen() { // minSteps[15][1<<15]
//    val tot = (1 shl n)-1
//    for (i in 0..n-1) for (j in 0..n-1) po[0][i][j] = INF
//    for (z in 0..n-1) {
//        val tmp = Array<IntArray>(1 shl n,{IntArray(n,{MOD})})
//        tmp[1 shl z][z] = 0
//        for (i in 0..tot) {
//            var sum = 0L
//            for (j in 0..n-1) if ((i shr j) % 2 == 1) sum += a[j]
//            for (j in 0..n-1) if ((i shr j) % 2 == 1) {
//                if (tmp[i][j] == MOD) continue
//                mx[z][tmp[i][j]] = maxOf(mx[z][tmp[i][j]],sum)
//                if (i == tot) po[0][z][j] = minOf(po[0][z][j],tmp[i][j].toLong())
//                for (k in 0..n-1) if ((i shr k) % 2 == 0) {
//                    val I = i+(1 shl k)
//                    tmp[I][k] = minOf(tmp[I][k],tmp[i][j]+dist[j][k])
//                }
//            }
//        }
//    }
////    for (i in 0..n-1) for (j in 0..n-1) {
////        // po[0][i][j] = dist[i][j].toLong()
////        println("PO ${i} ${j} ${po[0][i][j]}")
////    }
//    for (z in 1..49) {
//        for (i in 0..n-1) for (j in 0..n-1) {
//            po[z][i][j] = INF
//            for (k in 0..n-1)
//                po[z][i][j] = minOf(po[z][i][j],po[z-1][i][k]+po[z-1][k][j])
//        }
//    }
//}
//
//var s = 0
//
//fun tran(num: Long): LongArray {
//    var res = LongArray(n,{INF})
//    res[s-1] = 0
//    for (z in 0..49) if ((num shr z) % 2 == 1L) {
//        val tmp = LongArray(n,{INF})
//        for (i in 0..n-1) for (j in 0..n-1) {
//            tmp[j] = minOf(tmp[j],res[i]+po[z][i][j])
//        }
//        res = tmp
//    }
//    return res
//}
//
fun solve() {
    val N = rInt()
    val T = rInts(N).sorted().toIntArray()
//    println(T)
    val dp = Array<IntArray>(N+1) {IntArray(2*N+1) {MOD} }
    dp[0][1] = 0
    for (i in 0..N) for (j in 0..2*N) {
        if (j > 0) dp[i][j] = minOf(dp[i][j],dp[i][j-1])
        if (i < N && j < 2*N)
            dp[i+1][j+1] = minOf(dp[i+1][j+1],dp[i][j]+ abs(T[i]-j));
    }
    println(dp[N][2*N])
}

fun main() {
    val t = rInt()
    for (i in 1..t) solve()
//    val (a,b) = rInts(2)
//    val (_n,m,q,_s) = rInts(4)
//    n = _n
//    s = _s
//    a = rInts(n).toIntArray()
//    for (t in a) sum += t
//    for (i in 0..n-1) for (j in 0..n-1) if (i != j)
//        dist[i][j] = MOD
//    for (i in 1..m) {
//        val (v,u) = rInts(2)
//        dist[v-1][u-1] = 1
//    }
//    for (k in 0..n-1) for (i in 0..n-1) for (j in 0..n-1)
//        dist[i][j] = minOf(dist[i][j],dist[i][k]+dist[k][j])
//    // for (i in 0..n-1) for (j in 0..n-1) println("${i} ${j} ${dist[i][j]}")
//    gen()
//    for (i in 1..q) solve()
}