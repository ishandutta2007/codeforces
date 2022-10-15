private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var (n, m, k) = readInts()
    val MAX = 2000010
    var sol = IntArray(MAX)
    for (i in 1..n)
        sol[i] = 1000000000
    sol[k] = 0
    for (i in 1..m) {
        var (x, y) = readInts()
        sol[x]++
        sol[y]++
        var initx = sol[x] - 1
        var inity = sol[y] - 1
        if (initx < sol[y]) 
            sol[y] = initx
        if (inity < sol[x])
            sol[x] = inity
    }
    var print = IntArray(n)
    for (i in 1..n) 
        if (sol[i] <= m)
            print[i - 1] = sol[i]
        else
            print[i - 1] = -1
    println(print.joinToString(" "))        
}