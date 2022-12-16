import kotlin.math.*
import kotlin.collections.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var TT = readInt()
    while (TT-- != 0) {
        var s = readInts().toIntArray()
        
        var v1 = max(s[0], s[1])
        var v2 = max(s[2], s[3])
        if (v1 < v2) {
            v2 = v1.also{ v1 = v2 }
        }
        s.sort()

        var res = if (v1 == s[3] && v2 == s[2]) "YES" else "NO"
        println(res)
    }
}