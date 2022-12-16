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

private var MOD = 998244353L

fun modpow(_b: Long, _p: Long): Long {
    var b = _b
    var p = _p
    var ans = 1L
    while (p != 0L) {
        if ((p and 1) != 0L) {
            ans = ans*b%MOD
        }
        b = b*b%MOD
        p /= 2
    }
    return ans
}

var r = Array<IntArray>(21, {_ -> IntArray(50500)})

fun main() { output{
    var n = readInt()
    var m = readInt()
    var cnt = IntArray(n+2)
    for (i in 1..n) {
        for (j in 1..m) {
            r[i][j] = readInt()
        }
    }
    var fac = 1L
    for (i in 1..n) {
        fac = fac*i%MOD
    }
    var ifac = modpow(fac, MOD-2)
    var ans = 0L
    for (j in 1..m) {
        for (i in 1..n) {
            cnt[i] = 0
        }
        for (i in 1..n) {
            var v = max(1, n+2-r[i][j])
            cnt[v]++
        }
        var rem = 0
        var pcount = 1L
        for (i in 1..n) {
            rem += cnt[i]
            pcount = pcount*rem%MOD
            rem --
        }
        var tv = (1+MOD - (pcount*ifac)%MOD)%MOD
        //println("  $j -> $tv : 1-$pcount/$fac")
        ans += (1+MOD - (pcount*ifac)%MOD)%MOD
    }
    println(ans%MOD)
}}