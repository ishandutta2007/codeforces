import java.lang.StringBuilder

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    readInt()
    val s = readLn()
    val ans = StringBuilder()

    var depth = 0
    for (c in s)
        when (c) {
            '(' -> {
                depth++
                ans.append((depth and 1).toString())
            }
            ')' -> {
                ans.append((depth and 1).toString())
                depth--
            }
        }

    println(ans.toString())
}