import java.io.*
import java.util.*

private fun readWords() = readLine()!!.split(" ")

fun main() {
    if (System.getProperty("ONLINE_JUDGE") == null) {
        System.setIn(FileInputStream(File("test.inp")))
        System.setOut(PrintStream(File("test.out")))
    }

    val ntest = readLine()!!.toInt()
    for (testcase in 1..ntest) {
        val n = readLine()!!.toInt()
        val a = readWords().map(String::toLong).sorted()
        val ans = a.withIndex().map { (i, value) -> (n - i) * value }.max()
        println(ans)
    }
}