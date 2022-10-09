import java.io.*
import java.util.*

private const val fileName = "a"
fun main() {
    if (System.getProperty("ONLINE_JUDGE") == null) {
        assert(fileName != "")
        System.setIn(FileInputStream(File("$fileName.inp")))
        System.setOut(PrintStream(File("$fileName.out")))
    }
    val out = PrintWriter(System.out, false)
    val bf = BufferedReader(InputStreamReader(System.`in`))
    var stok = StringTokenizer("")
    fun read(): String {
        while (!stok.hasMoreTokens()) stok = StringTokenizer(bf.readLine())
        return stok.nextToken()
    }

    fun solve() {
        var n = read().toInt()
        var k = read().toInt()
        for (i in 0 until k) {
            if (n % 10 == 0) n /= 10
            else n--
        }
        out.println(n)
    }

    solve()
    out.flush()
}