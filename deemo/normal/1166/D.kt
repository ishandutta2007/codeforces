import java.lang.Long.max
import java.lang.Long.min
import kotlin.math.max

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toLong() } // list of ints

fun main() {
    val q = readInt()

    repeat(q) {
        val (a, b, m) = readInts()
        fun f(x: Int) = 1L shl x

        var cur = a
        var sm = a
        var t = 0
        while (sm + 1 <= b) {
            cur = sm + 1
            sm += cur
            t++
        }

        val ans = mutableListOf(a)
        sm = a
        for (i in 1..t) {
            var temp = sm + 1
            val ff = f(max(0, t - i-1))
            val c = min((b - cur)/ ff, m-1)

            cur += c*ff
            temp += c
            ans.add(temp)
            sm += temp
        }
        if (cur != b)
            print("-1\n")
        else {
            print("" + ans.size + " " + ans.joinToString(" ") + "\n")
        }
    }
}