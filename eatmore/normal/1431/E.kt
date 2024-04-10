import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun sortBy(a: IntArray, n: Int, v: IntArray) {
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

fun solve() {
    val tests = scanInt()
    for (test in 0 until tests) {
        val n = scanInt()
        val a = IntArray(n)
        val b = IntArray(n)
        val idxA = IntArray(n)
        val idxB = IntArray(n)
        for (i in 0 until n) {
            a[i] = scanInt()
            idxA[i] = i
        }
        for (i in 0 until n) {
            b[i] = scanInt()
            idxB[i] = i
        }
        sortBy(idxA, n, a)
        sortBy(idxB, n, b)
        var ans = 0
        var ansM = 0
        var l = 0
        var r = n
        while (true) {
            val m = l + r shr 1
            var cans1 = Int.MAX_VALUE / 2
            for (i in 0 until m) {
                cans1 = Math.min(cans1, b[idxB[n - m + i]] - a[idxA[i]])
            }
            var cans2 = Int.MAX_VALUE / 2
            for (i in 0 until n - m) {
                cans2 = Math.min(cans2, a[idxA[m + i]] - b[idxB[i]])
            }
            val cans = Math.min(cans1, cans2)
            if (ans < cans) {
                ans = cans
                ansM = m
            }
            if (l >= r) {
                break
            }
            if (cans1 > cans2) {
                l = m + 1
            } else {
                r = m - 1
            }
        }
        val p = IntArray(n)
        for (i in 0 until ansM) {
            p[idxA[i]] = idxB[n - ansM + i]
        }
        for (i in 0 until n - ansM) {
            p[idxA[ansM + i]] = idxB[i]
        }
        for (i in 0 until n) {
            out.print((p[i] + 1).toString() + " ")
        }
        out.println()
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