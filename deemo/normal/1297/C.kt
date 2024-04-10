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
        val a = readInts()
        val b = MutableList(n) {0}
        var sum = 0
        var mn = 1e9.toInt()
        var mx = -1e9.toInt()
        for (x in a)
            if (x > 0) {
                sum += x
                mn = minOf(mn, x)
            } else if (x < 0) {
                mx = maxOf(mx, x)
            }

        if (-mx >= mn) {
            addOL("${sum - mn}")
            for (i in 0 until n)
                if (a[i] > 0) {
                    b[i] = 1
                    if (a[i] == mn) {
                        b[i] = 0
                        mn = -1
                    }
                }
        } else {
            addOL("${sum + mx}")
            for (i in 0 until n)
                if (a[i] < 0) {
                    if (a[i] == mx) {
                        b[i] = 1
                        mx = 2;
                    }
                } else if (a[i] > 0) {
                    b[i] = 1
                }
        }
        addOL(b.joinToString(""))
    }
    outputRes()
}