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

private var N = 200200

var ans = IntArray(N)
var s = ""
var n = 0
var zc = IntArray(N)
var oc = IntArray(N)
var zp = IntArray(N)
var op = IntArray(N)

fun getans(r: Int): Int {
    var ans = 0
    var idx = 1
    while (idx <= n) {
        var zeros = zc[idx-1]
        var ones = oc[idx-1]
        idx = max(zp[zeros+r+1], op[ones+r+1])
        ++ans
    }
    return ans
}

fun solve(lo: Int, hi: Int, lsol: Int, hsol: Int) {
    if (hi < lo) {
        return
    }
    if (lsol == hsol) {
        for (i in lo..hi) {
            ans[i] = lsol
        }
        return
    }
    var mid = (lo+hi)/2
    ans[mid] = getans(mid)
    solve(lo, mid-1, lsol, ans[mid])
    solve(mid+1, hi, ans[mid], hsol)
}

fun setup() {
    for (i in 0..(N-1)) {
        zp[i] = n+1
        op[i] = n+1
    }
    zp[0] = 0
    op[0] = 0
    for (i in 1..n) {
        zc[i] = zc[i-1]
        oc[i] = oc[i-1]
        if (s[i-1] == '0') {
            ++zc[i]
            zp[zc[i]] = i
        } else if (s[i-1] == '1') {
            ++oc[i]
            op[oc[i]] = i
        }
    }
}

fun main() {
    s = read()
    n = s.length
    setup()
    var lim = min(zc[n], oc[n])
    solve(1, lim-1, 0x3f3f3f3f, 2)
    solve(lim, n, 1, 1)
    var b = Array<Int>(n, {idx -> ans[idx+1]})
    //var b = Array<Int>(n, {idx -> getans(idx+1)})
    println(b.joinToString(" "))
    //println("!!  $evals")
}