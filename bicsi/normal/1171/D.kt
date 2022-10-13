import java.lang.Math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    var (A, D, M) = readInts()
    var (g, p, b) = readInts()

    if (A > g) {
        println("NO")
        return
    }
    g -= A
    M -= b
    if (M < 0) M = 0
    if (M + D > g + p) {
        println("NO")
        return
    }
    println("YES")
}