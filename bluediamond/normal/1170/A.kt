private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
fun main(args: Array<String>) {
    var t = readInt()
    for (tc in 0..t - 1) {
        var (x, y) = readInts()
        var mn = y
        if (x < y) 
            mn = x
        var mx = x + y - mn
        var a = mn - 1
        var b = 1
        var c = mx - a
        println("${a} ${b} ${c}")
    }
}