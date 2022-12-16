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

// 8:21
fun main() { output{
    var TT = readInt()
    while (TT-- != 0) {
        var (n, m) = readInts(2)
        var a = ArrayList<Int>(readInts(n))
        var dirs = ArrayList<String>(readStrings(n))
        var ans = IntArray(n)
        for (i in 0..(n-1)) {
            ans[i] = -1
        }
        for (modv in 0..1) {
            var _indices = ArrayList<Int>()
            for (i in 0..(n-1)) {
                if (a[i]%2 == modv) {
                    //println("    WITH $modv take $i")
                    _indices.add(i)
                }
            }
            _indices.shuffle()
            var indices = ArrayList<Int>(_indices.sortedBy({i: Int -> a[i]}))
            var q = ArrayList<Int>()
            for (i in indices) {
                if (q.size > 0 && dirs[i][0] == 'L') {
                    assert(dirs[q.get(q.size-1)][0] == 'R')
                    var itime = (a[i] - a[q.get(q.size-1)])/2
                    ans[i] = itime
                    ans[q.get(q.size-1)] = itime
                    //println("   -> assign $i, ${q.get(q.size-1)}")
                    q.removeAt(q.size-1)
                } else if (dirs[i][0] == 'R') {
                    q.add(i)
                } else if (q.size == 0 && dirs[i][0] == 'L') {
                    q.add(i)
                    dirs[i] = "R"
                    a[i] = -a[i]
                    //println(" ADD $i -> ${a[i]}")
                }
            }
            while (q.size > 1) {
                var j = q.get(q.size-1)
                q.removeAt(q.size-1)
                var i = q.get(q.size-1)
                q.removeAt(q.size-1)
                var itime = (2*m-a[j]-a[i])/2
                //println("   -> assign $i, $j")
                ans[i] = itime
                ans[j] = itime
            }
            //println("  !! ${q.size}")
        }
        println(ans.joinToString(" "))
    }
}}