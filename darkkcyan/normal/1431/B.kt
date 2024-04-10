import java.io.*
import java.util.*

private fun readWords() = readLine()!!.split(" ")

fun main() {
    if (System.getProperty("ONLINE_JUDGE") == null) {
        System.setIn(FileInputStream(File("test.inp")))
        System.setOut(PrintStream(File("test.out")))
    }

    val ntest = readLine()!!.toInt()
    for (testcase in 1 .. ntest) {
        val s = readLine()!!.trim()
        val n = s.length
        val ans = s.count { it == 'w' } + s.split("w").map { it.length / 2 }.sum()
        println(ans)
    }

}