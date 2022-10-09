import java.io.*
import java.util.*

private fun readWords() = readLine()!!.split(" ")

fun main() {
    if (System.getProperty("ONLINE_JUDGE") == null) {
        System.setIn(FileInputStream(File("test.inp")))
        System.setOut(PrintStream(File("test.out")))
    }

    fun Boolean.toInt() = if (this) 1 else 0
    fun doRound(num: Int): Int {
        if (num < 1000) return num
        if (num < 1_000_000) return num + (num % 1000 >= 500).toInt() * 1000
        return num + (num % 1_000_000 >= 500_000).toInt() * 1_000_000
    }

    fun Int.toShortString(): String {
        return (
            if (this < 1000) "$this"
            else if (this < 1_000_000) "${this / 1000}K"
            else "${this / 1_000_000}M"
        )
    }

    for (i in 0 until readLine()!!.toInt()) {
        val num = readLine()!!.toInt()
        println(doRound(num).toShortString())
    }
}