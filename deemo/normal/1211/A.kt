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
    var b=-1 to -1;
    var c=-1 to -1;
    for ((i, x) in a.withIndex()) {
        if (b.first == -1){
            b = x to i
        }
        else if (c.first == -1) {
            if (b.first != x) {
                c = x to i
            }
        }
        else if (x != b.first && x != c.first) {
            val f = mutableListOf(b, c, x to i)
            f.sortBy { it.first }
            println("${f[0].second+1} ${f[1].second+1} ${f[2].second+1}")
            return
        }
    }
    println("-1 -1 -1")
}