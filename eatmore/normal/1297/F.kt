import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

object F {
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

    @Throws(Exception::class)
    fun solve() {
        val tests = scanInt()
        for (test in 0 until tests) {
            val n = scanInt()
            val m = scanInt()
            val a = IntArray(n)
            val idxA = IntArray(n)
            val b = IntArray(n)
            for (i in 0 until n) {
                a[i] = scanInt()
                idxA[i] = i
                b[i] = scanInt()
            }
            sortBy(idxA, n, a)
            val toks = PriorityQueue<Token>()
            val ans = IntArray(n)
            var ansV = 0
            var curDay = -1
            for (i in idxA) {
                val nextDay = a[i]
                toks@ while (curDay < nextDay && !toks.isEmpty()) {
                    for (j in 0 until m) {
                        val t = toks.remove()
                        ans[t.i] = curDay
                        ansV = Math.max(ansV, curDay - t.v)
                        if (toks.isEmpty()) {
                            break@toks
                        }
                    }
                    ++curDay
                }
                curDay = nextDay
                toks.add(Token(b[i], i))
            }
            toks@ while (!toks.isEmpty()) {
                for (j in 0 until m) {
                    val t = toks.remove()
                    ans[t.i] = curDay
                    ansV = Math.max(ansV, curDay - t.v)
                    if (toks.isEmpty()) {
                        break@toks
                    }
                }
                ++curDay
            }
            out!!.println(ansV)
            for (i in 0 until n) {
                out!!.print(ans[i].toString() + " ")
            }
            out!!.println()
        }
    }

    @Throws(IOException::class)
    fun scanInt(): Int {
        return scanString().toInt()
    }

    @Throws(IOException::class)
    fun scanLong(): Long {
        return scanString().toLong()
    }

    @Throws(IOException::class)
    fun scanString(): String {
        while (tok == null || !tok!!.hasMoreTokens()) {
            tok = StringTokenizer(`in`!!.readLine())
        }
        return tok!!.nextToken()
    }

    var `in`: BufferedReader? = null
    var out: PrintWriter? = null
    var tok: StringTokenizer? = null
    fun main() {
        try {
            `in` = BufferedReader(InputStreamReader(System.`in`))
            out = PrintWriter(System.out)
            solve()
            `in`!!.close()
            out!!.close()
        } catch (e: Throwable) {
            e.printStackTrace()
            System.exit(1)
        }
    }

    internal class Token(val v: Int, val i: Int) : Comparable<Token> {
        override fun compareTo(o: Token): Int {
            return v - o.v
        }

    }
}

fun main() {
    F.main()
}