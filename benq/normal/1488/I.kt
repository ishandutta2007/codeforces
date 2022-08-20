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
// https://github.com/bqi343/USACO/blob/master/Implementations/content/various/kotlinOld.kt

import java.io.*
import java.lang.Math.abs
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


//fun solve() {
//    val (n,m) = io.ints(2)
//    val w = io.ints(n)
//    repeat(m) {
//        val t = io.int()
//        if (t == 1) {
//            val (i,c) = io.ints()
//            num[i] += c
//        } else if (t == 2) {
//
//        } else {
//
//        }
//    }
//}

class Dinic(_N: Int) {
    data class Edge(val to: Int, val rev: Int, var flo: Int, var cap: Int) {};
    val N: Int
    val adj: ArrayList<ArrayList<Edge>>
    var lev: ArrayList<Int>
    var ptr: ArrayList<Int>
    init {
        N = _N;
        adj = ArrayList<ArrayList<Edge>>()
        for (i in 0..N-1) {
            adj.add(ArrayList<Edge>())
        }
//        println("INITED ${N}")
        lev = ArrayList<Int>()
        ptr = ArrayList<Int>()
    }
    fun ae(a: Int, b: Int) {
//        println("ADDING ${a} ${b}")
//        println(adj.size)
        adj[a].add(Edge(b,adj[b].size,0,1))
        adj[b].add(Edge(a,adj[a].size-1,0,0));
    }
    fun bfs(s: Int, t: Int): Boolean { // level = shortest distance from source
//        println("BFS ${s} ${t}")
        lev = ArrayList<Int>()
        ptr = ArrayList<Int>()
        for (i in 0..N-1) {
            lev.add(0)
            ptr.add(0)
        }
        lev[s] = 1;
        val q = LinkedList<Int>()
        q.push(s)
        while (!q.isEmpty()) {
            val u = q.pollLast();
            for (e in adj[u]) if (e.flo < e.cap && lev[e.to] == 0) {
                q.push(e.to)
                lev[e.to] = lev[u]+1;
            }
        }
        return lev[t] != 0;
    }
    fun dfs(v: Int, t: Int): Boolean {
//        println("DFS ${v} ${t}")
        if (v == t) return true;
        while (ptr[v] < adj[v].size) {
            val e = adj[v][ptr[v]];
            val dif = e.cap-e.flo;
            if (lev[e.to]!=lev[v]+1 || dif == 0) {
                ptr[v] ++
                continue
            };
            if (dfs(e.to,t)) {
                e.flo += 1; adj[e.to][e.rev].flo -= 1;
                return true;
            } // saturated >=1 one edge
            ptr[v] ++
        }
        return false;
    }
    fun maxFlow(s: Int, t: Int): Int {
        var tot = 0;
        while (bfs(s,t)) {
//            println(lev)
            while (dfs(s,t)) ++tot
        }
//        println("DONE MAX FLOW")
        return tot;
    }
}

fun solve() {
    val start = System.currentTimeMillis()
    val (n,m,k) = io.ints(3) // OK
    val adj = Array<ArrayList<Int>>(n){ArrayList<Int>()} // OK
    val ed = ArrayList<ArrayList<Int>>()
    repeat(m) {
        val (_x,_y) = io.ints(2)
        val x = _x-1
        val y = _y-1
        adj[x].add(y)
        adj[y].add(x)
        ed.add(arrayListOf(x,y))
    }
    val dist = IntArray(n){-1}
    val q = LinkedList<Int>()
    dist[0] = 0
    q.push(0)
    while (!q.isEmpty()) {
        val x = q.pollLast()
//        println("HA ${x}")
        for (i in adj[x]) if (dist[i] == -1) {
            dist[i] = dist[x]+1
            q.push(i)
        }
    }
    val hi = Array<ArrayList<Int>>(n){ArrayList<Int>()}
    val lo = Array<ArrayList<Int>>(n){ArrayList<Int>()}
    val important = ArrayList<ArrayList<Int>>()
    val D = Dinic(n+m+2)
    for (e in ed) {
        if (dist[e[0]] > dist[e[1]])
            e[0] = e[1].also { e[1] = e[0] }
        if (dist[e[0]]+1 == dist[e[1]]) {
            val cnt = important.size
            important.add(ArrayList())
            if (dist[e[0]]%2 == 0) {
                val v = n+2+cnt
                D.ae(0,v)
                D.ae(v,e[0]+2)
                D.ae(v,e[1]+2)
            } else {
                val v = n+2+cnt
                D.ae(v,1)
                D.ae(e[0]+2,v)
                D.ae(e[1]+2,v)
            }
        }
    }
    println(minOf(D.maxFlow(0,1),k))
//    assert(important.size >= 100)
//    var timer = 0
//    val visLo = IntArray(n){-1}
//    val visHi = IntArray(n){-1}
//    val match = IntArray(m){-1}
//    val visited = IntArray(m){-1}
//    fun makeMatch(a: Int, b: Int): Boolean {
//        match[a] = b
//        match[b] = a
//        return true
//    }
//    fun dfsMatch(x: Int): Boolean {
//        if (x == -1) return true
//        if (visited[x] == timer) return false
//        visited[x] = timer
//        val a = important[x][0]
//        val b = important[x][1]
//        if (visLo[a] != timer) {
//            visLo[a] = timer
////            for (i in lo[a]) if (match[i] == -1) {
////                return makeMatch(x,i)
////            }
//            for (i in lo[a]) if (dfsMatch(match[i])) {
//                return makeMatch(x,i)
//            }
//        }
//        if (visHi[b] != timer) {
//            visHi[b] = timer
//            for (i in hi[b]) if (dfsMatch(match[i])) {
//                return makeMatch(x,i)
//            }
//        }
//        return false
//    }
//    fun dumb(x: Int): Boolean {
//        val a = important[x][0]
//        val b = important[x][1]
//        for (i in lo[a]) if (match[i] == -1) {
//            return makeMatch(x,i)
//        }
//        for (i in hi[b]) if (match[i] == -1) {
//            return makeMatch(x,i)
//        }
//        return false
//    }
//    var ans = 0
//    for (i in 0..important.size-1) if (match[i] == -1 && dist[important[i][0]]%2 == 0) {
//        ans += if (dumb(i)) 1 else 0
//    }
//    for (i in 0..important.size-1) if (match[i] == -1 && dist[important[i][0]]%2 == 0) {
////        println(System.currentTimeMillis()-start)
//        if (System.currentTimeMillis()-start > 7000) break
//        ++timer
//        if (dfsMatch(i)) ++ans
//    }
//    println(minOf(ans,k))

//    for (i in dist) println(i)
//    println(dist)
}

fun main() {
//    val t = io.int()
    val t = 1
    repeat(t) { solve() }
    io.close()
}