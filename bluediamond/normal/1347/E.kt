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
        var n = readInt()
        if (n < 4) {
            println(-1)
        } else {
            var sol = ArrayList<Int>()
            for (j in 1..n) {
                var i = n + 1 - j
                if (i % 2 == 1) 
                    sol.add(i)
            }
            sol.add(4)
            sol.add(2)
            for (i in 6..n) 
                if (i % 2 == 0) 
                    sol.add(i)
            println(sol.joinToString(" ")) 
        }
    }
}