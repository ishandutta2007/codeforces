private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val te = readInt()
    repeat (te) {
        readInt()
        val s = readLn()
        val pos = s.indexOf("8")
        if (pos == -1 || s.length - pos < 11)
            println("NO")
        else
            println("YES")
    }
}