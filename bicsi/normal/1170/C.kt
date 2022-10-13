import java.lang.Math.max
import java.lang.Math.min
import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints


fun main(args: Array<String>) {
    val tests = readInt()
    for (test in 1..tests) {
        val s = readLn().toCharArray()
        val t = readLn().toCharArray()

        var at = 0
        var ok = true
        for (c in t) {
            if (at >= s.size) {
                ok = false
                break
            }
            if (s[at] == c) {
                ++at
            } else {
                if (at + 1 < s.size && s[at] == '-' && s[at + 1] == '-' && c == '+') {
                    at += 2
                } else {
                    ok = false
                    break
                }
            }
        }

        if (at != s.size) ok = false
        if (ok) {
            println("YES")
        } else {
            println("NO")
        }

    }
}