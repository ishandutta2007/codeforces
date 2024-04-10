import java.io.*
import java.util.*
private const val fileName = "b"

private inline fun <T> readSplit(transform: (String) -> T, delimiter: String) =
    readLine()!!.split(delimiter).map(transform)

fun main() {
    if (System.getProperty("ONLINE_JUDGE") == null) {
        assert(fileName != "")
        System.setIn(FileInputStream(File("$fileName.inp")))
        System.setOut(PrintStream(File("$fileName.out")))
    }

    val n = readLine()!!.toInt()
    val s = readLine()!!
    val hashMap = HashMap<String, Int>()
    val ma = hashMap

    for (i in 0 until n - 1) {
        val sub = s.substring(i, i + 2)
        ma[sub] = (ma[sub] ?: 0)  + 1
    }
    val ans = ma.maxBy {it.value}!!.key
    print(ans)
}