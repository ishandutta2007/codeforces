private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {

    var (n, w) = readInts()
    var a = readInts()
    var su = 0
    var mn = 0
    var mx = 0

    for(i in 0..n-1){
        su += a[i]
        if (mn > su) mn = su
        if (mx < su) mx = su
    }

    if (mn > 0) mn = 0
    if (mx < 0) mx = 0
    var ans = w - mx + mn + 1
    if (ans < 0) ans = 0
    
    println(ans)
}