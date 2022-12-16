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

private var n = 0
private var a = ArrayList<Int>()
private var N = 5050
private var INF = 0x3f3f3f3f
private var dp = Array<IntArray>(N, {_ -> IntArray(N)})

fun main() { output{
    n = readInt()
    a.add(0)
    var starts = ArrayList<Int>()
    for (i in 1..n) {
        var x = readInt()
        a.add(x)
        if (x != 0) {
            starts.add(i)
        }
    }
    for (i in (0..n)) {
        for (j in (0..(N-1))) {
            dp[i][j] = INF
        }
    }
    dp[0][0] = 0
    for (i in (1..n)) {
        for (j in (0..(starts.size))) {
            dp[i][j] = dp[i-1][j]
            if (a[i] == 0 && j > 0) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + abs(i-starts[j-1]))
            }
        }
    }
    println(dp[n][starts.size])
}}