import java.lang.Math.max
import java.lang.Math.min
import java.util.*
import kotlin.collections.ArrayList

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints


fun main(args: Array<String>) {
    val n = readInt()
    val seq = readInts().toIntArray()
    val cnt = seq.count { it == -1 }
    val ans = Array(cnt){ mutableListOf<Int>() }
    val ended = BooleanArray(cnt) {false}

    var rem = (0..cnt-1).toList().toIntArray()

    var at = 0
    for (elem in seq) {
        if (elem == -1) ended[rem[at]] = true
        else ans[rem[at]].add(elem)

        at += 1
        if (at == rem.size) {
            rem = rem.filter { ended[it] == false }.toIntArray()
            at = 0
        }
    }

    println(cnt)
    for (x in ans)
        println((intArrayOf(x.size) + x).joinToString(separator = " "))
}