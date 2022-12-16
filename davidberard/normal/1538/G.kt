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

fun attempt(x: Long, y: Long, a: Long, b: Long, m: Long): Boolean {
    if (a == b) {
        return a*m <= x && a*m <= y
    }
    if (b*m > x) {
        return false
    }
    /*
    a*r + b*(m-r) <= x
    (a - b)r + bm <= x
    (a - b)r <= x - bm
    */
    var r: Long = min((x - b*m) / (a - b), m)
    //println(" FOR $m : ${(m-r)*a} + ${r*b} vs $y ")
    return (m - r)*a + r*b <= y
}

fun solve(x: Long, y: Long, a: Long, b: Long) {
    var lo = 0L
    var hi = (x+y)
    while (lo < hi) {
        var mid = (lo+hi+1)/2
        var res = attempt(x, y, a, b, mid)
        if (res) {
            lo = mid
        } else {
            hi = mid-1
        }
    }
    println(lo)
}

fun main() { output{
    var TT = readInt()
    while (TT-- != 0) {
        var (x, y, a, b) = readLongs(4)
        solve(x, y, max(a, b), min(a, b))
    }
}}