import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun sortBy(a: IntArray, n: Int, v: LongArray) {
    if (n == 0) {
        return
    }
    for (i in 1 until n) {
        var j = i
        val ca = a[i]
        val cv = v[ca]
        do {
            val nj = j - 1 shr 1
            val na = a[nj]
            if (cv <= v[na]) {
                break
            }
            a[j] = na
            j = nj
        } while (j != 0)
        a[j] = ca
    }
    var ca = a[0]
    for (i in n - 1 downTo 1) {
        var j = 0
        while ((j shl 1) + 2 + Int.MIN_VALUE < i + Int.MIN_VALUE) {
            j = j shl 1
            j += if (v[a[j + 2]] > v[a[j + 1]]) 2 else 1
        }
        if ((j shl 1) + 2 == i) {
            j = (j shl 1) + 1
        }
        var na = a[i]
        a[i] = ca
        ca = na
        val cv = v[ca]
        while (j != 0 && v[a[j]] < cv) {
            j = j - 1 shr 1
        }
        while (j != 0) {
            na = a[j]
            a[j] = ca
            ca = na
            j = j - 1 shr 1
        }
    }
    a[0] = ca
}

const val INF = Long.MAX_VALUE / 2

fun solve() {
    val n = scanInt()
    val m = scanInt()
    val q = scanInt()
    val s = scanInt() - 1
    val a = LongArray(n)
    var total: Long = 0
    for (i in 0 until n) {
        a[i] = scanLong()
        total += a[i]
    }
    val can = Array(n) { BooleanArray(n) }
    for (i in 0 until m) {
        can[scanInt() - 1][scanInt() - 1] = true
    }
    val dyn1 = Array(n) { Array(n) { IntArray(1 shl n) } }
    val queue = IntArray(n shl n + 1)
    for (start in 0 until n) {
        val cdyn1 = dyn1[start]
        for (end in 0 until n) {
            Arrays.fill(cdyn1[end], Int.MAX_VALUE)
        }
        cdyn1[start][1 shl start] = 0
        queue[0] = start
        queue[1] = 1 shl start
        var queueHead = 0
        var queueTail = 2
        do {
            val curPos = queue[queueHead++]
            val curSet = queue[queueHead++]
            val curDist = cdyn1[curPos][curSet]
            val nextDist = curDist + 1
            for (nextPos in 0 until n) {
                val nextSet = curSet or (1 shl nextPos)
                if (can[curPos][nextPos] && cdyn1[nextPos][nextSet] > nextDist) {
                    cdyn1[nextPos][nextSet] = nextDist
                    queue[queueTail++] = nextPos
                    queue[queueTail++] = nextSet
                }
            }
        } while (queueHead < queueTail)
    }
    val dyn2 = Array(n) { IntArray(1 shl n) }
    for (start in 0 until n) {
        for (set in 0 until (1 shl n)) {
            var v = Int.MAX_VALUE
            for (end in 0 until n) {
                v = Math.min(v, dyn1[start][end][set])
            }
            dyn2[start][set] = v
        }
    }
    val dyn3 = Array(50) { Array(n) { LongArray(n) } }
    for (start in 0 until n) {
        for (end in 0 until n) {
            dyn3[0][start][end] = dyn1[start][end][(1 shl n) - 1].toLong()
        }
    }
    for (i in 1 until dyn3.size) {
        val cdynCur = dyn3[i]
        val cdynPrev = dyn3[i - 1]
        for (start in 0 until n) {
            for (end in 0 until n) {
                var cur = INF
                for (mid in 0 until n) {
                    cur = Math.min(cur, cdynPrev[start][mid] + cdynPrev[mid][end])
                }
                cdynCur[start][end] = cur
            }
        }
    }
    val sums = LongArray(1 shl n)
    for (i in 1 until (1 shl n)) {
        val j = Integer.numberOfTrailingZeros(i)
        sums[i] = sums[i xor (1 shl j)] + a[j]
    }
    val sumSets = IntArray(1 shl n)
    for (i in 0 until (1 shl n)) {
        sumSets[i] = i
    }
    sortBy(sumSets, 1 shl n, sums)
    val sumsSorted = LongArray(1 shl n)
    for (i in 0 until (1 shl n)) {
        sumsSorted[i] = 2 * sums[sumSets[i]]
    }
    val dyn4 = Array(n) { IntArray(1 shl n) }
    for (start in 0 until n) {
        var prev = Int.MAX_VALUE
        for (i in (1 shl n) - 1 downTo 0) {
            prev = Math.min(prev, dyn2[start][sumSets[i]])
            dyn4[start][i] = prev
        }
    }
    var curDists = LongArray(n)
    var nextDists = LongArray(n)
    for (qq in 0 until q) {
        val c = scanLong()
        Arrays.fill(curDists, INF)
        curDists[s] = 0
        val laps = c / total
        for (i in 0..59) {
            if (laps and (1L shl i) != 0L) {
                for (next in 0 until n) {
                    var v = INF
                    for (cur in 0 until n) {
                        v = Math.min(v, curDists[cur] + dyn3[i][cur][next])
                    }
                    nextDists[next] = v
                }
                val t = curDists
                curDists = nextDists
                nextDists = t
            }
        }
        val need = c % total
        var pos = Arrays.binarySearch(sumsSorted, 2 * need - 1)
        if (pos < 0) {
            pos = pos.inv()
        }
        var ans = INF
        for (i in 0 until n) {
            ans = Math.min(ans, dyn4[i][pos] + curDists[i])
        }
        out.println(ans)
    }
}

fun scanInt(): Int {
    return scanString().toInt()
}

fun scanLong(): Long {
    return scanString().toLong()
}

fun scanString(): String {
    var t = tok
    while (t == null || !t.hasMoreTokens()) {
        t = StringTokenizer(inp.readLine())
        tok = t
    }
    return t.nextToken()
}

val inp = BufferedReader(InputStreamReader(System.`in`))
val out = PrintWriter(System.out)
var tok: StringTokenizer? = null

fun main() {
    solve()
    inp.close()
    out.close()
}