import java.io.*
import java.util.*

private fun readWords() = readLine()!!.split(" ")

fun main() {
    if (System.getProperty("ONLINE_JUDGE") == null) {
        System.setIn(FileInputStream(File("test.inp")))
        System.setOut(PrintStream(File("test.out")))
    }

    for (testcase in 0 until readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val ans = BooleanArray(n)
        val inp = readWords().map {it.toInt()}.withIndex().filter {it.value != 0}.sortedByDescending { it.value }
        var sum = 0
        var prev = inp[0]
        var removePrev = true
        for (i in inp) {
            if (i.value > 0) {
                sum += i.value
                prev = i
                ans[i.index] = true
                continue
            }
            if (sum + i.value > sum - prev.value) {
                sum += i.value
                ans[i.index] = true
                removePrev = false
            }
            break
        }
        if (removePrev) {
            sum -= prev.value
            ans[prev.index] = false
        }
        println(sum)
        println(ans.map{if (it) "1" else "0"}.joinToString(""))
    }

}