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
    val n = readInt()
    val a = readInts()
    var ans = 0
    var mx1 = -1
    var mx2 = -1
    for (x in a) {
        if (x < mx2)
            ans++
        mx2 = maxOf(mx2, x)
        if (mx2 > mx1) {
            mx1 = mx2.also({mx2=mx1})
        }
    }
    println(ans)
}