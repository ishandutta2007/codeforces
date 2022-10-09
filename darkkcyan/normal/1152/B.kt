import java.io.*
import java.util.*

fun main() {
    val out = PrintWriter(System.out, false)
    val bf = BufferedReader(InputStreamReader(System.`in`))
    var stok = StringTokenizer("")
    fun read(): String {
        while (!stok.hasMoreTokens()) stok = StringTokenizer(bf.readLine())
        return stok.nextToken()
    }

    fun solve() {
        var x = read().toInt()
        val ans = ArrayList<Int>()
        if (x % 2 == 0) {
            ans.add(0)
            ++x
        }
        while (x != 1) {
            val t = 32 - Integer.numberOfLeadingZeros(x)
            ans.add(t)
            x = x xor ((1 shl t) - 1)
            ++x
        }
        out.println(ans.size * 2)
        ans.forEach { out.print("$it ") }
    }

    solve()
    out.flush()
}

// the real main