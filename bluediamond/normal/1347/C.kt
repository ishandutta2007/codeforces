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
        var a = ArrayList<Int>()
        var len = 0
        var num = 100000
        while (num > 0) {
            var inc = n / num
            var lol = inc * num
            n -= lol
            if (lol > 0) {
                a.add(lol)
                len++
            }
            num /= 10
        }
        println(len)
        println(a.joinToString(" "))
    }

}