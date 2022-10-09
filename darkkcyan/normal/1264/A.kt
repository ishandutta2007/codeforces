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
    var ntest = read().toInt()
    while (ntest-- > 0) {
        var n = read().toInt()
        var a = IntArray(n) { read().toInt() }
        var diff_pos = ArrayList<Int>()
        for (i in 1 until n) {
            if (a[i - 1] != a[i])
                diff_pos.add(i)
        }
        while (diff_pos.size > 0 && diff_pos.last() > n / 2)
            diff_pos.removeAt(diff_pos.size - 1)

        if (diff_pos.isEmpty()) {
            out.println("0 0 0")
            continue
        }

//        err.println(diff_pos)
        val g = diff_pos[0]
        var s = -1
        for (i in diff_pos) {
            if (i - g > g) {
                s = i - g
                break
            }
        }
        val b = diff_pos.last() - s - g
        if (g <= 0 || s <= g || b <= g) {
            out.println("0 0 0")
        } else {
            out.printf("%d %d %d\n", g, s, b)
        }

    }
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