import java.io.*
import java.util.*

private fun readWords() = readLine()!!.split(" ")

fun main() {
    if (System.getProperty("ONLINE_JUDGE") == null) {
        System.setIn(FileInputStream(File("test.inp")))
//        System.setOut(PrintStream(File("test.out")))
    }
    val ntest = readLine()!!.toInt()
    for (testcase in 1 .. ntest) {
        val n = readLine()!!.toInt()
        val a = readWords().map(String::toInt)
        val b = readWords().map(String::toInt)

        var ans = IndexedValue(-1, -1)
        for (shift in 0 until n) {
            var minDiff = Int.MAX_VALUE
            for (i in 0 until n) {
                minDiff = Math.min(Math.abs(a[i] - b[(i + shift) % n]), minDiff)
            }
//            System.err.println("$shift $minDiff")
            if (ans.value < minDiff) {
                ans = IndexedValue(shift, minDiff)
            }
        }
        println(IntArray(n) { (it + ans.index) % n + 1 }.joinToString(" "){ it.toString()})
    }

}