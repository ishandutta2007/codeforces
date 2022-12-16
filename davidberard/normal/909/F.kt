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

fun popcount(_a: Int): Int {
    var a = _a
    var ans = 0
    while (a != 0) {
        ans += a%2
        a /= 2
    }
    return ans
}
fun bitcnt(_a: Int): Int {
    var a = _a
    var ans = 0
    while (a != 0) {
        ++ans
        a /= 2
    }
    return ans
}

fun main() { output{
    var n = readInt()
    if (n%2 == 0) {
        var a = IntArray(n+1)
        println("YES")
        var m = n
        while (m != 0) {
            var r = m
            while (true) {
                if (popcount(r) == bitcnt(r)) {
                    break
                }
                --r
            }
            var i = 0
            while (r+i+1 <= m) {
                a[r+i+1] = r-i
                a[r-i] = r+i+1
                ++i
            }
            m = r-i
        }
        var b = Array<Int>(n, {idx -> a[idx+1]})
        println(b.joinToString(" "))
    } else {
        println("NO")
    }
    if (popcount(n) != 1 && n >= 6) {
        println("YES")
        var a = IntArray(n+1)
        var of = Array<ArrayList<Int>>(19, {_ -> ArrayList<Int>()});

        of[0].add(1)
        of[0].add(3)
        of[1].add(2)
        of[1].add(6)
        of[2].add(4)
        of[2].add(5)

        for (i in 7..n) {
            var r = bitcnt(i)-1
            of[r].add(i)
        }
        for (i in 0..18) {
            for (j in 0..(of[i].size-1)) {
                a[of[i][j]] = of[i][(j+1)%of[i].size]
            }
        }
        var b = Array<Int>(n, {idx -> a[idx+1]})
        println(b.joinToString(" "))
    } else {
        println("NO")
    }
}}