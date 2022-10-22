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
        val n = readInt()
        val segs = mutableListOf<Pair<Int, Int>>()
        val pos = mutableListOf<Int>()
        for (i in 0 until n) {
            val (a, b) = readInts()
            segs.add(a to b)
            pos.add(a)
            pos.add(b)
            pos.add(a-1)
            pos.add(a+1)
            pos.add(b-1)
            pos.add(b+1)
        }

        var done = false
        for (x in pos) {
            var count = 0
            for (y in segs)
                if (y.first <= x && x <= y.second) {
                    count++
                    if (count > 1)
                        break
                }
            if (count == 1) {
                addOL("${x}")
                done = true
                break
            }

        }
        if (!done)
            addOL("-1")
    }
    outputRes()
}