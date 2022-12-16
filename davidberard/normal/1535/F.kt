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

private var RT = 9000
private var N = 200200
private var RRT = N/RT + 10
var mp = HashMap<ArrayList<Int>, ArrayList<Int>>()
var s = Array<String>(N, {_ -> ""})
private var n = 0
private var len = 0

var MOD1 = 1000000007
var BASE1 = 1789
var MOD2 = 1000000009
var BASE2 = 1787
var pw1 = LongArray(RRT)
var reps1 = Array<LongArray>(26, {_ -> LongArray(RRT)})
var pw2 = LongArray(RRT)
var reps2 = Array<LongArray>(26, {_ -> LongArray(RRT)})

fun setup() {
    pw1[0] = 1
    pw2[0] = 1
    for (j in 0..25) {
        reps1[j][0] = 0
        reps1[j][0] = 0
    }
    for (i in 1..(RRT-1)) {
        pw1[i] = pw1[i-1]*BASE1%MOD1
        pw2[i] = pw2[i-1]*BASE2%MOD2
        for (j in 0..25) {
            reps1[j][i] = (reps1[j][i-1] + pw1[i-1]*(j + 'a'.toInt()))%MOD1
            reps2[j][i] = (reps2[j][i-1] + pw2[i-1]*(j + 'a'.toInt()))%MOD2
        }
    }
}

fun main() { output{
    setup()
    n = readInt()
    for (i in 1..n) {
        s[i] = read()
        var arr = ArrayList<Int>(26)
        for (j in 1..26) {
            arr.add(0)
        }
        for (c in s[i]) {
            arr[c.toInt()-'a'.toInt()]++
        }
        if (!mp.containsKey(arr)) {
            mp.put(arr, ArrayList<Int>())
        }
        mp.get(arr)!!.add(i)
    }
    len = s[1].length
    var ans = 0L
    if (n < RT) {
        var seen = 0
        var mismatch = IntArray(len+10)
        for ((_, _indices) in mp) {
            _indices.shuffle(kotlin.random.Random(1231223))
            var indices = _indices.sortedWith({a: Int, b: Int -> s[a].compareTo(s[b])})
            for (i in 0..(indices.size-1)) {
                for (x in 1..(len-1)) {
                    mismatch[x] = mismatch[x-1] + (if (s[indices[i]][x-1] > s[indices[i]][x]) 1 else 0)
                }
                for (j in (i+1)..(indices.size-1)) {
                    var x = s[indices[i]]
                    var y = s[indices[j]]
                    var pfx = 0
                    var sfx = 0
                    for (k in 0..(len-1)) {
                        if (x[k] == y[k]) {
                            ++pfx
                        } else {
                            break
                        }
                    }
                    for (k in (len-1) downTo 0) {
                        if (x[k] == y[k]) {
                            ++sfx
                        } else {
                            break
                        }
                    }
                    ans += if (mismatch[len-sfx-1] - mismatch[pfx] == 0) 1 else 2
                }
            }
            ans += seen.toLong() * indices.size * 1337
            seen += indices.size.toInt()
        }
    } else {
        var counts = IntArray(26)
        var pfxCode1 = LongArray(RRT)
        var sfxCode1 = LongArray(RRT)
        var pfxCode2 = LongArray(RRT)
        var sfxCode2 = LongArray(RRT)
        var seen = 0
        for ((_, _indices) in mp) {
            _indices.shuffle(kotlin.random.Random(123123))
            var indices = _indices.sortedWith({a: Int, b: Int -> s[a].compareTo(s[b])})
            var hashes = HashSet<Long>();
            for (i in indices) {
                var t = s[i]
                for (x in 0..(len-1)) {
                    pfxCode1[x+1] = (pfxCode1[x]+t[x].toInt()*pw1[x])%MOD1
                    pfxCode2[x+1] = (pfxCode2[x]+t[x].toInt()*pw2[x])%MOD2
                }
                for (y in (len-1) downTo 0) {
                    sfxCode1[y+1] = (sfxCode1[y+2] + t[y].toInt()*pw1[y])%MOD1
                    sfxCode2[y+1] = (sfxCode2[y+2] + t[y].toInt()*pw2[y])%MOD2
                }
                var matches = 0
                for (x in 0..(len-1)) {
                    for (j in 0..25) {
                        counts[j] = 0
                    }
                    for (y in x..(len-1)) {
                        counts[t[y].toInt()-'a'.toInt()]++
                        var start_char = 25
                        var end_char = 0
                        for (j in 25 downTo 0) {
                            if (counts[j] > 0) {
                                start_char = j
                            }
                        }
                        for (j in 0..25) {
                            if (counts[j] > 0) {
                                end_char = j
                            }
                        }
                        if (start_char + 'a'.toInt() == t[x].toInt()) {
                            continue
                        }
                        if (end_char + 'a'.toInt() == t[y].toInt()) {
                            continue
                        }

                        var sorthash1 = pfxCode1[x] + sfxCode1[y+2]
                        var sorthash2 = pfxCode2[x] + sfxCode2[y+2]
                        var pcur = x
                        var extra1 = 0L
                        var extra2 = 0L
                        for (j in 0..25) 
                        {
                            extra1 += pw1[pcur]*reps1[j][counts[j]]%MOD1
                            extra2 += pw2[pcur]*reps2[j][counts[j]]%MOD2
                            pcur += counts[j]
                        }
                        sorthash1 = (extra1 + sorthash1)%MOD1
                        sorthash2 = (extra2 + sorthash2)%MOD2
                        var sorthash = sorthash1*MOD1 + sorthash2
                        if (hashes.contains(sorthash)) {
                            ++ans
                            ++matches
                        }
                    }
                }

                ans += (hashes.size - matches)*2

                var thash1 = 0L
                var thash2 = 0L
                for (j in 0..(len-1)) {
                    thash1 = (thash1 + t[j].toInt()*pw1[j])%MOD1
                    thash2 = (thash2 + t[j].toInt()*pw2[j])%MOD2
                }
                thash1 %= MOD1
                thash2 %= MOD2
                var thash = thash1*MOD1 + thash2
                assert(!hashes.contains(thash))
                hashes.add(thash)
            }
            ans += seen.toLong() * indices.size * 1337
            seen += indices.size.toInt()
        }
    }
    println(ans)
}}