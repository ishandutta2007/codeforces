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
    for (i in 0..n-1) {
        var x = readInts()
        var y = readInts()
        var ok = 0
        for (f in 0..1)
            for (s in 0..1)
                if (x[f] == y[s] && x[1 - f] + y[1 - s] == x[f])
                    ok = 1
        if (ok == 1)
            println("Yes")
        else
            println("No")
    }
}