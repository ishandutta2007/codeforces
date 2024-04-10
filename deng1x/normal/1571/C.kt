import kotlin.math.max
import kotlin.math.min

fun getSuffix(s1: String, s2: String): Int {
    val len = min(s1.length, s2.length)
    for (i in 0 until len) {
        if (s1[s1.length - 1 - i] != s2[s2.length - 1 - i]) {
            return i
        }
    }
    return len
}

fun main() {
    repeat(readLine()!!.toInt()) {
        var low = 0
        var high = Int.MAX_VALUE
        repeat(readLine()!!.toInt()) {
            val (s1, s2, rhyme) = readLine()!!.split(" ")
            val suffix = getSuffix(s1, s2)
            when (rhyme) {
                "1" -> high = min(high, suffix)
                "0" -> low = max(low, suffix + 1)
            }
        }
        if (high < low) {
            println(0)
            return@repeat
        }
        println(high - low + 1)
        println((low..high).joinToString(" "))
    }
}