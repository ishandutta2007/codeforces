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
        var (n, k1, k2) = readInts()
        var v1 = k1
        var v2 = 0
        if (k2 - k1 < k1)
            v2 = k2 - k1
        else 
            v2 = k1
        var str = readLn()
        var i = 0
        var sol = 0L
        while (i < n) {
            if (str[i] == '0') {
                i++
                continue
            }
            var j = i
            while (j + 1 < n && str[j + 1] == '1') 
                j++
            var dif = j - i + 1
            var c2 = dif / 2
            var c1 = dif - c2
            sol += c1.toLong() * v1
            sol += c2.toLong() * v2
            i = j + 1;
        }
        println(sol)
    }
}