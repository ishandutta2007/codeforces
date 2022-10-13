import java.lang.Math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    val (x, y, z) = readInts()
    var res: Int = x
    res = min(res, y - 1)
    res = min(res, z - 2)
    println(res * 3 + 3)
}