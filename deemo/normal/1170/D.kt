import java.util.*

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
    val m = readInt()
    val a = readInts()
    var n = 0
    for (x in a)
        if (x == -1)
            n++

    var rem = TreeSet<Int>()
    for (i in 0 until n)
        rem.add(i)

    val ans = Array(n) { mutableListOf<Int>()}

    var i = 0
    while (i < m) {
        val tempS = TreeSet<Int>()
        for (x in rem) {
            val y = a[i++]
            if (y != -1){
                tempS.add(x)
                ans[x].add(y)
            }
        }
        rem = tempS
    }

    addOL(n.toString())
    for (i in 0 until n) {
        val temp = mutableListOf(ans[i].size)
        for (x in ans[i])
            temp.add(x)
        addOL(temp.joinToString(" "))
    }
    outputRes()
}