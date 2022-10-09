import java.io.*
import java.util.*

private val err = System.err
private const val fileName = "test"
private lateinit var out: PrintWriter
private lateinit var bf: BufferedReader
private var stok = StringTokenizer("")
private fun read(): String {
    while (!stok.hasMoreTokens()) stok = StringTokenizer(bf.readLine())
    return stok.nextToken()
}

private fun solve() {
    val cnt = bf.readLine().trim().split(' ').map(String::toInt).toIntArray()

    if (cnt[0] + cnt[1] + cnt[2] + cnt[3] == 1) {
        out.println("YES")
        out.print("0".repeat(cnt[0]) + "1".repeat(cnt[1]) + "2".repeat(cnt[2]) + "3".repeat(cnt[3]))
        return
    }
    if (cnt[0] == 1 && cnt[1] == 0 && cnt[2] == 0 && cnt[3] == 1) {
        out.println("NO")
        return
    }

    val complement = arrayOf(1, 0, 3, 2)
    fun try_solve(beg: Int, end: Int): Boolean {
        val cur_cnt= cnt.copyOf()
        assert(beg <= end)

        var fake_beg = beg
        var fake_end = end
        if (beg == 0 || beg == 3) {
            --cur_cnt[beg]
            fake_beg = complement[beg]
        }
        if (end == 0 || end == 3) {
            --cur_cnt[end]
            fake_end = complement[end]
        }

        cur_cnt[1] -= cur_cnt[0]
        cur_cnt[2] -= cur_cnt[3]
        if (cur_cnt.any {it < 0}) return false
        if (cur_cnt[1] == 0 && cur_cnt[0] > 0) return false
        if (cur_cnt[2] == 0 && cur_cnt[3] > 0) return false
        val g1 = cur_cnt[1]
        val g2 = cur_cnt[2]
        if (fake_beg == 1 && fake_end == 1) {
            if (g1 - 1 != g2) return false
        } else if (fake_beg == 1 && fake_end == 2) {
            if (g1 != g2) return false
        } else if (fake_beg == 2 && fake_end == 2) {
            if (g1 + 1 != g2) return false
        } else assert(false)

        out.println("YES")
        if (beg != fake_beg) out.printf("%d ", beg)
        err.printf("%d %d", beg, end)

        var cur = fake_beg
        while (cur_cnt[2] + cur_cnt[1] > 0) {
            out.printf("%d ", cur)
            --cur_cnt[cur]
            while (cur_cnt[complement[cur]] > 0) {
                --cur_cnt[complement[cur]]
                out.printf("%d %d ", complement[cur], cur)
            }
            cur = 3 - cur
        }
        if (end != fake_end) out.printf("%d ", end)
        return true
    }

    for (beg in 0 until 4) {
        for (end in beg until 4)
            if (try_solve(beg, end)) return
    }

    out.println("NO")
}

fun main() {
    if (System.getProperty("ONLINE_JUDGE") == null) {
        assert(fileName != "")
        System.setIn(FileInputStream(File("$fileName.inp")))
        System.setOut(PrintStream(File("$fileName.out")))
    }

    out = PrintWriter(System.out!!, false)
    bf = BufferedReader(InputStreamReader(System.`in`))

    solve()
    out.flush()
}