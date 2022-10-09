import java.io.*
import java.util.*

private fun readWords() = readLine()!!.split(" ")

fun main() {
    if (System.getProperty("ONLINE_JUDGE") == null) {
        System.setIn(FileInputStream(File("test.inp")))
//        System.setOut(PrintStream(File("test.out")))
    }

    val ntest = readLine()!!.toInt()
    for (testcase in 1..ntest) {
        val (n, k) = readWords().map(String::toInt)
        val a = readWords().map(String::toLong)
        val sum = LongArray(n + 1)
        for (i in 0 until n) {
            sum[i + 1] = sum[i] + a[i]
        }
        var ans = 0L
        for (i in 1 .. n) {
            val free = i / k
            ans = (sum[n - i + free] - sum[n - i]).coerceAtLeast(ans)
        }
        println(ans)
    }
}