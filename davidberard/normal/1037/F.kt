import kotlin.math.*
import kotlin.collections.*
import kotlin.system.*
import java.util.StringTokenizer
import java.io.PrintWriter
import java.util.TreeSet
import java.util.PriorityQueue

fun fail(message: String): Nothing {
    throw IllegalArgumentException(message)
}

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

private var MOD = 1000000007L

private inline fun cappedTriangleSum(rmax: Long, width: Long, k: Long): Long {
    var uncapped = ( (k-1) * ( (rmax * (rmax + 1) / 2) % MOD) ) % MOD
    var rstart = (width)/(k-1) + 1
    //var rstart = (width+k-2)/(k-1)
    //assert(rstart == (width+k-2)/(k-1))
    var rcap = (rmax - rstart + 1)
    var cap = ( (k-1) * ( (rcap * (rcap + 1) / 2) % MOD) ) % MOD
    if (!(width >= (rstart-1)*(k-1))) {
        fail("Width too small")
    }
    if (!(width <= (rstart)*(k-1))) {
        fail("Width too big")
    }
    var ans = (uncapped - cap + (rmax - (rstart-1))* (width - (rstart-1) *(k-1)) )
    //println("  SOLVE($rmax, $width, $k): Uncapped $uncapped; rstart $rstart; rcap $rcap; cap $cap, ans $ans")
    return (ans%MOD + MOD)%MOD
}

fun main() {
    var (n, k) = readInts(2)
    var a = IntArray(n+1)
    var ts = LongArray(n)
    for (i in 1..n) {
        a[i] = readInt()
        ts[i-1] = (2000000000-a[i])*(1L shl 32) + i
    }
    ts.shuffle()
    ts.sort()
    var st = TreeSet<Int>()
    st.add(0)
    st.add(n+1)
    var ans = 0L
    for (va in ts) {
        var idx = (va and ((1L shl 32)-1)).toInt()
        var lwr = st.lower(idx)!!
        var hgr = st.higher(idx)!!
        if (hgr - lwr <= k) {
            continue
        }
        var rmax = (hgr-lwr-2)/(k-1)
        var topv = cappedTriangleSum(rmax.toLong(), (hgr-idx-1).toLong(), k.toLong())
        var lowv = cappedTriangleSum(rmax.toLong(), (idx-lwr-1).toLong(), k.toLong())
        var sub = ( (k-1) * ( (rmax.toLong() * (rmax + 1) / 2) %MOD) ) %MOD
        var cur = (topv + lowv + MOD - sub + rmax)%MOD
        ans += ( cur * a[idx] )%MOD
        st.add(idx)
    }
    println(ans%MOD)
}