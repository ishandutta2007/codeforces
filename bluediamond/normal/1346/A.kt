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
    for (i in 0..t - 1) {
        var (n, k) = readInts()
        var ans = 0L
        ans = 1L + k + k * k + k * k * k
        var n1 = n / ans
        var n2 = n1 * k
        var n3 = n2 * k
        var n4 = n3 * k
        println("${n1} ${n2} ${n3} ${n4}")
    }
}