import java.io.*
import java.util.*

private const val localFileName = "test"
private lateinit var out: PrintWriter
private lateinit var bf: BufferedReader
private var stok = StringTokenizer("")
private fun read(): String {
    while (!stok.hasMoreTokens()) stok = StringTokenizer(bf.readLine())
    return stok.nextToken()
}

private fun solve() {
    val (n, m) = bf.readLine().trim().split(' ').map(String::toInt)
    val a = Array(n + 2) {
        if (it == 0 || it == n + 1) BooleanArray(m + 2) { false }
        else ("." + bf.readLine().trim() + ".").map {it == 'X'}.toBooleanArray()
    }

    class Filler {
        private val data = Array(n + 2) { IntArray(m + 2 )}

        fun fillRect(r1: Int, c1: Int, r2: Int, c2: Int) {
            change(r1, c1, 1)
            if (c2 <= m) change(r1, c2 + 1, -1)
            if (r2 <= n) change(r2 + 1, c1, -1)
            if (r2 <= n && c2 <= m) change(r2 + 1, c2 + 1, 1)
        }

        private fun change (r: Int, c: Int, value: Int) {
            data[Math.max(r, 0)][Math.max(c, 0)] += value
        }

        fun getResult(): Array<BooleanArray> {
            val ans = Array(n + 2) { BooleanArray(m + 2)}
            for (i in 0 until n + 2) {
                for (f in 0 until m + 2) {
                    if (i > 0) data[i][f] += data[i - 1][f]
                    if (f > 0) data[i][f] += data[i][f - 1]
                    if (i > 0 && f > 0) data[i][f] -= data[i - 1][f - 1]
                    ans[i][f] = data[i][f] > 0
                }
            }
            return ans
        }
    }

    fun get_source(range: Int): Array<BooleanArray> {
        val findSourceFiller = Filler()
        for (i in 0 until n + 2) {
            for (f in 0 until m + 2) {
                if (a[i][f]) continue
                findSourceFiller.fillRect(i - range, f - range, i + range, f + range)
            }
        }

        return findSourceFiller.getResult()
    }

    fun ok(range: Int): Boolean {
        val cur_source = get_source(range)
        val recoverFiller = Filler()
        for (i in 0 until n + 2) {
            for (f in 0 until m + 2) {
                if (cur_source[i][f]) continue
                recoverFiller.fillRect(i - range, f - range, i + range, f + range)
            }
        }

        val res = recoverFiller.getResult()
        return res.contentDeepEquals(a)
    }

    var l = 0
    var r = 1
    while (ok(r)) r *= 2
    while (l < r) {
        val mid = (l + r + 1) / 2
        if (ok(mid)) l = mid
        else r = mid - 1
    }

    out.println(l)
    val source = get_source(l)
    for (i in 1..n) {
        out.println(source[i].map { if (it) '.' else 'X' }.joinToString("").substring(1, m + 1))
    }
}

fun main() {
    if (System.getProperty("ONLINE_JUDGE") == null) {
        assert(localFileName != "")
        System.setIn(FileInputStream(File("$localFileName.inp")))
        System.setOut(PrintStream(File("$localFileName.out")))
    }

    out = PrintWriter(System.out!!, false)
    bf = BufferedReader(InputStreamReader(System.`in`))

    solve()
    out.flush()
}