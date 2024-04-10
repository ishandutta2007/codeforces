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

fun main() { output{
    var n = readInt()
    var _a = readInts(n)
    var _b = readInts(n+1)
    var a = Array<Int>(n, {idx -> _a[idx]})
    var b = Array<Int>(n+1, {idx -> _b[idx]})
    a.shuffle()
    a.sort()
    b.shuffle()
    b.sort()
    var m = readInt()
    var c = readInts(m)
    var pre = IntArray(n+4)
    var suf = IntArray(n+4)
    pre[0] = -0x3f3f3f3f
    suf[n+2] = -0x3f3f3f3f
    for (i in 1..(n)) {
        pre[i] = max(pre[i-1], b[i-1]-a[i-1])
        //println(" .. ${n+2-i} ${n+3-i} vs ${suf.size} ; ${n+1-i} vs ${b.size} ; ${n-i} vs ${a.size}")
        suf[n+2-i] = max(suf[n+3-i], b[n+1-i] - a[n-i])
    }
    var res = ArrayList<Int>()
    for (x in c) {
        var lo = 0
        var hi = n // the new 0-based index
        while (lo < hi) {
            var mid = (lo+hi)/2
            if (a[mid] < x) { // cannot go at position mid
                lo = mid+1
            } else {
                hi = mid
            }
        }
        var ans = max(max(pre[lo], suf[lo+2]), b[lo] - x)
        res.add(ans)
    }
    println(res.joinToString(" "))
}}