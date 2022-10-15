private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) { 
    val MAX = 1000 + 7
    var sumr = LongArray(MAX)
    var sumc = LongArray(MAX)
    var a = LongArray(MAX)
    var b = LongArray(MAX)
    var c = LongArray(MAX)
    var d = LongArray(MAX)
    var mt = LongArray(MAX * MAX)
    var (n, m, q) = readInts()
    for (i in 0..n - 1) {
        var a = readLongs()
        for (j in 0..m - 1) {
            mt[i * m + j] = a[j]
            sumr[i + 1] += a[j]
            sumc[j + 1] += a[j]
        }
    }
    var print = ArrayList<Long>()
    for (op in 0..q) {
        if (op > 0) {
            var (r, cc, xxxx) = readInts()
            r--
            cc--
            var nw = xxxx.toLong()
            sumr[r + 1] -= mt[r * m + cc]
            sumc[cc + 1] -= mt[r * m + cc]
            mt[r * m + cc] = nw
            sumr[r + 1] += mt[r * m + cc]
            sumc[cc + 1] += mt[r * m + cc]
        }
        var sum = 0L
        for (i in 1..n) {
            a[i] = a[i - 1] + sum
            sum += sumr[i]
        }
        sum = 0L
        for (j in 1..n) {
            var i = n + 1 - j
            b[i] = b[i + 1] + sum
            sum += sumr[i]
        }
        sum = 0L
        for (i in 1..m) {
            c[i] = c[i - 1] + sum
            sum += sumc[i]
        }
        sum = 0L
        for (j in 1..m) {
            var i = m + 1 - j
            d[i] = d[i + 1] + sum
            sum += sumc[i]
        }
        var mn1 = 0L
        var mn2 = 0L
        mn1 = a[1] + b[1]
        for (i in 2..n) {
            if (a[i] + b[i] < mn1) 
                mn1 = a[i] + b[i]
        }
        mn2 = c[1] + d[1]
        for (i in 2..m) {
            if (c[i] + d[i] < mn2) 
                mn2 = c[i] + d[i]
        }
        print.add(mn1 + mn2)
    }
    println(print.joinToString(" "))
}