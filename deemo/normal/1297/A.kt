private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double

private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of long
private fun readDoubles() = readStrings().map { it.toDouble() } // list of double

private val OL = mutableListOf<String>()
private fun addOL(s: String){
    OL.add(s)
}
private fun outputRes() {
    println(OL.joinToString("\n"))
}

private val MAXN = 1e5.toInt()
private val MOD = 1e9.toInt() + 7

fun main() {
    val t = readInt()
    repeat(t) {
        var n = readInt()
        if (n < 1000) {
            addOL(n.toString())
        } else if (n < 1e6.toInt()) {
            val m = n % 1000
            n /= 1000
            if (m >= 500)
                n++
            if (n < 1000) {
                addOL("${n}K")
            } else {
                addOL("1M")
            }
        } else {
            val m = n % 1e6.toInt()
            n /= 1e6.toInt()
            if (m >= 5e5.toInt())
                n++
            addOL("${n}M")
        }
    }
    outputRes()
}