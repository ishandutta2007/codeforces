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
    var a = readInts()
    var idm = 0
    for (i in 1..n-1) 
        if (a[i] >= a[idm])
            idm = i
    var ans = (a[idm].toLong() - 1) * n + idm + 1
    println(ans)
}