import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

object C {
    @Throws(Exception::class)
    fun solve() {
        val tests = scanInt()
        for (test in 0 until tests) {
            val n = scanInt()
            val a = IntArray(n)
            var bestI = -1
            var bestVal = Int.MAX_VALUE
            var sum = 0
            for (i in 0 until n) {
                a[i] = scanInt()
                if (a[i] != 0 && Math.abs(a[i]) < bestVal) {
                    bestVal = Math.abs(a[i])
                    bestI = i
                }
                if (a[i] > 0) {
                    sum += a[i]
                }
            }
            out!!.println(sum - bestVal)
            for (i in 0 until n) {
                out!!.print(if ((a[i] > 0) xor (i == bestI)) 1 else 0)
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
}

fun main() {
    C.main()
}