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
        var a = readInts()
        var x = 0
        var y = 0
        var s = 1
        var ant = 0
        var l = 0
        var r = n - 1
        while (l <= r) {
            if (s % 2 == 1) {
                var cur = 0
                while (l <= r && cur <= ant) {
                    cur += a[l]
                    l++
                }
                ant = cur
                x += cur
            } else {
                var cur = 0
                while (l <= r && cur <= ant) {
                    cur += a[r]
                    r--
                }
                ant = cur
                y += cur
            }
            s++
        }
        println("${s - 1} ${x} ${y}")
    }
}