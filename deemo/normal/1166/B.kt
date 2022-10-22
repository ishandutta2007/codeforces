import java.lang.StringBuilder
import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val n = readInt()
    val ls = listOf('a', 'e', 'i', 'o', 'u')
    for (i in 1..n)
        if (n % i == 0 && min(n/i, i) >= 5) {
            val ans = StringBuilder()
            for (r in 0 until i)
                for (c in 0 until n/i)
                    ans.append(ls[(c+r)%ls.size])
            println(ans.toString())
            return
        }
    println(-1)
}