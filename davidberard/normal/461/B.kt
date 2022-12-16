import kotlin.math.*
import kotlin.collections.*
import java.util.StringTokenizer
import java.io.PrintWriter

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
inline fun output(block: PrintWriter.() -> Unit) { _writer.apply(block).flush() }

fun gcd(a: Long, b: Long): Long {
    if (b == 0L) {
        return a
    }
    return gcd(b, a%b)
}

private var N = 100100
private var MOD = 1000000007L
private var n = 0
private var adj = Array<ArrayList<Int>>(N, {_ -> ArrayList<Int>()})
private var a = IntArray(N)
private var dp = Array<LongArray>(2, {_ -> LongArray(N)})

fun modpow(_b: Long, _p: Long): Long {
    var b = _b
    var p = _p
    var ans = 1L
    while (p != 0L) {
        if (p%2 == 1L) {
            ans = ans * b % MOD
        }
        b = b*b%MOD
        p /= 2
    }
    return ans
}

fun dfs(u: Int) {
    if (adj[u].size == 0) {
        dp[a[u]][u] = 1L
        //println(" $u : ${dp[0][u]} ; ${dp[1][u]}")
        return
    }
    var zpow = 1L
    for (v in adj[u]) {
        dfs(v)
        zpow = zpow * (dp[1][v] + dp[0][v]) % MOD
    }
    if (a[u] == 0) {
        dp[0][u] = zpow
        for (v in adj[u]) {
            dp[1][u] += zpow * modpow((dp[1][v] + dp[0][v])%MOD, MOD-2) % MOD * dp[1][v] %MOD
        }
        dp[1][u] %= MOD
    } else {
        dp[1][u] = zpow
    }
    //println(" $u : ${dp[0][u]} ; ${dp[1][u]}")
}

/*
var ep = LongArray(N)

fun efs(u: Int) {
    if (adj[u].size == 0) {
        ep[u] = 1
        return
    }
    for (v in adj[u]) {
        efs(v)
    }
}
*/

fun main() { output{
    n = readInt()
    for (i in 2..n) {
        var p = readInt()
        p++
        adj[p].add(i)
    }
    for (i in 1..n) {
        a[i] = readInt()
    }
    dfs(1)
    //efs(1)
    println(dp[1][1])
}}