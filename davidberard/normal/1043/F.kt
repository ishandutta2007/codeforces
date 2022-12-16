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

var MOD = (1e9+7).toLong()
private var N = 300300
//private var N = 20

fun modpow(_b: Long, _p: Long): Long {
    var b = _b
    var p = _p
    var ans = 1L
    while (p!= 0L) {
        if (p%2 == 1L) {
            ans = ans * b % MOD
        }
        b = b*b % MOD
        p /= 2
    }
    return ans
}

var fac = LongArray(N)
var ifac = LongArray(N)
fun setup() {
    fac[0] = 1L
    ifac[0] = 1L
    for (i in 1..(N-1)) {
        fac[i] = fac[i-1]*i%MOD
    }
    ifac[N-1] = modpow(fac[N-1], MOD-2)
    for (i in (N-2) downTo 1) {
        ifac[i] = ifac[i+1] * (i+1)%MOD
    }
}
fun choose(n: Int, k: Int): Long {
    return fac[n] * ifac[k] % MOD * ifac[n-k] % MOD
}

var valsAt = IntArray(N)
var a = IntArray(N)
var cnt = IntArray(N)
var dp = Array<LongArray>(8, {_ -> LongArray(N)})
var n = 0

fun build() {
    for (i in 1..(N-1)) {
        for (j in i..(N-1) step i) {
            cnt[i] += valsAt[j]
        }
    }
}

fun main() { output{
    setup()
    n = readInt()
    for (i in 1..n) {
        a[i] = readInt()
        valsAt[a[i]]++
    }
    build()
    var ans = -1
    for (i in 1..7) {
        for (j in (N-1) downTo 1) {
            if (i > cnt[j]) {
                continue
            }
            dp[i][j] = choose(cnt[j], i)
            for (k in (j*2)..(N-1) step j) {
                dp[i][j] -= dp[i][k]
            }
            dp[i][j] = (dp[i][j]%MOD + MOD)%MOD
            //println(" dp $i $j : ${dp[i][j]}")
        }
        if (dp[i][1] != 0L) {
            ans = i
            break
        }
    }
    println(ans)
}}