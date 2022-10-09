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
        val n = readLine()!!.toInt()
        val a = readWords().map{it.toInt()}.withIndex()
            .sortedBy { it.value }

        val ans = mutableListOf<Int>()
        var f = n - 1
        var isFirst = true
        for (i in 0 until n) {
            val left = f - i
            val need = a[i].value + if (isFirst) 0 else -1
            if (left < need) {
                break
            }
            for (x in 1..need) {
                ans.add(a[f--].index)
            }
            ans.add(a[i].index)
            isFirst = false
        }
        while (ans.size < n) {
            ans.add(a[f--].index)
        }
        println(ans.joinToString(" ") { (it + 1).toString() })
    }
}