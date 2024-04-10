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
        val idx = IntArray(n)
        for (i in 0 until n) {
            a[i] = scanInt()
            idx[i] = i
        }
        sortBy(idx, n, a)
        var left = n - 1
        val ans = IntArray(n)
        Arrays.fill(ans, -1)
        var p = n
        for (i in 0 until n) {
            if (left >= a[idx[i]]) {
                left -= a[idx[i]]
                ans[n - 1 - left] = idx[i]
            } else {
                p = i
                break
            }
        }
        run {
            var i = 0
            var j = p
            while (i < n) {
                if (ans[i] < 0) {
                    ans[i] = idx[j++]
                }
                i++
            }
        }
        for (i in 0 until n) {
            out.print((ans[i] + 1).toString() + " ")
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