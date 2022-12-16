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
    var TT = readInt()
    for (_tt in 1..TT) {
        var (n, k) = readInts(2)
        var str = read()
        var have = 0
        for (i in 0..(n-1)) {
            if (str[i] == '1') {
                have++
            }
        }
        var vec = Array<Int>(n, {idx -> idx})
        var idx = 0
        var ans = 0
        while (have > 0) {
            vec[idx] = -1
            ++ ans
            if (str[idx] == '1') {
                --have
            }
            var nxt = idx
            var incr = 0
            while (have > 0 && incr < k) {
                nxt = (nxt+1)%n
                if (vec[nxt] != -1) {
                    ++incr
                }
            }
            idx = nxt
        }
        println(ans)

    }
}}