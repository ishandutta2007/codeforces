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

class Segtree(var h: Int) {
    var n: Int = 1.shl(h)
    var cur = CharArray(n*2)
    var t = IntArray(n*2)
    fun pull(x: Int) {
        when(cur[x]) {
            '1' -> t[x] = t[x*2+1]
            '0' -> t[x] = t[x*2]
            '?' -> t[x] = t[x*2+1] + t[x*2]
        }
    }
    fun build() {
        for (i in (n-1) downTo 1) {
            pull(i)
        }
    }
    fun update(xi: Int, c: Char) {
        var x = xi
        cur[x] = c
        while (x > 0) {
            pull(x)
            x/= 2
        }
    }
    fun get_count(): Int {
        return t[1]
    }
}

fun allone(xi: Int): Boolean {
    var x = xi
    var steps = 0
    var ones = 0
    while (x > 0) {
        if (x%2 == 1) {
            ones++
        }
        steps++
        x /= 2
    }
    return steps == ones
}

var k = 0
var a = CharArray(1)
var idx = IntArray(1.shl(19))

fun main() {
output{
    k = readInt()
    a = readLn().toCharArray()
    var st = Segtree(k)
    var cval = 1.shl(k)-2
    var jval = cval
    for (i in 1..(1.shl(k)-1)) {
        idx[cval] = i
        cval++
        if (allone(i)) {
            cval = jval - i - 1
            jval = cval
        }
    }
    for (i in (1.shl(k))..(1.shl(k+1)-1)) {
        st.t[i] = 1
    }
    for (i in 0..(1.shl(k)-2)) {
        st.cur[idx[i]] = a[i]
    }
    st.build()
    var q= readInt()
    while (q-- != 0) {
        var (ps, cs) = readStrings(2)
        st.update(idx[ps.toInt()-1], cs[0])
        println(st.get_count())
    }
}
}