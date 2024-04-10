private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
fun main(args: Array<String>) {
    var n = readInt()
    var v = readInts()
    var mx = -1
    var mx2 = -1
    var bad = 0
    for (i in 0..n - 1) {
        if (v[i] > mx) {
            mx2 = mx
            mx = v[i]
        } else 
            if (v[i] > mx2) 
                mx2 = v[i]
        if (mx2 > v[i])
            bad++
    }
    println(bad)
}