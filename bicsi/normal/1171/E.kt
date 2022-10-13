import java.lang.Math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    val n = readInt()
    val s = readLn()

    val hs = HashSet<Char>()
    for (x in s.toCharArray()) {
        hs.add(x)
    }
    if (hs.size == n && n > 1) {
        println("No")
    } else {
        println("Yes")
    }
}