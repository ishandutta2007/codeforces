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

private var MOD1 = 0L
private var MOD2 = 0L
private var b1 = 0L
private var b2 = 0L
private var hh = LongArray(100100)
private var st = Array<String>(100100, {_ -> ""})

fun hsh1(s: String): Long {
    var h = 0L
    for (c in s) {
        h = (h*b1 + c.toLong())%MOD1
    }
    return h
}
fun hsh2(s: String): Long {
    var h = 0L
    for (c in s) {
        h = (h*b2 + c.toLong())%MOD2
    }
    return h
}
fun hsh(s: String): Long {
    return (hsh1(s) shl 32) + hsh2(s)
}

fun getprime(lo: Long, hi: Long): Long {
    var pr = kotlin.random.Random.nextLong(hi-lo) + lo
    while (true) {
        var good = true
        var i = 2L
        while (i*i <= pr) {
            if (pr%i == 0L) {
                good = false
                break
            }
            i ++
        }
        if (good) {
            break
        }
        pr ++
    }
    return pr
}

fun main() { output{
    /*
    MOD1 = getprime(1000000000L, 1100000000L)
    MOD2 = getprime(1000000000L, 1100000000L)
    b1 = getprime(1000L, 10000L)
    b2 = getprime(1000L, 10000L)
    */
    MOD1 = 1000000007
    MOD2 = 1000000009
    b1 = 27
    b2 = 27
    var (n, k) = readInts(2)
    var mp = HashMap<Long, Int>()
    for (i in 1..n) {
        st[i] = read()
        hh[i] = hsh(st[i])
        mp[hh[i]] = i
        //println("  $i -> ${hh[i]}")
    }
    var q = readInt()
    var sb = StringBuilder()
    var sk = Array<String>(k+1, {_ -> ""})
    for (_q in 1..q) {
        var t = read()
        var ans = 0

        for (i in 0..k) {
            sb.clear()
            for (j in 0..k) {
                if (i == j) {
                    continue
                }
                sb.append(t[j])
            }
            sk[i] = sb.toString()
            var bad = false
            for (j in 0..(i-1)) {
                if (sk[i] == sk[j]) {
                    bad = true
                }
            }
            //println(" !! ${sk[i]} is bad? $bad .. ${hsh(sk[i])}")
            if (!bad && mp.containsKey(hsh(sk[i]))) {
                ans ++
            }
        }
        println(ans)
    }
}}