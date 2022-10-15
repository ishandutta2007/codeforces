private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {      
val MAX = 200000 + 7
        var a = IntArray(MAX)
        var b = IntArray(MAX)
        var c = IntArray(MAX)
        var sol = IntArray(MAX)
    var t = readInt()
    for (tc in 0..t - 1) {
 
        var (n, m) = readInts()
        for (i in 1..n) 
            sol[i] = 0
        for (i in 1..m) {
            var (x, y, z) = readInts()
            a[i] = x
            b[i] = y
            c[i] = z
            if (sol[x] < z) sol[x] = z
            if (sol[y] < z) sol[y] = z
        }
        var ok = 1
        for (i in 1..m) {
            var mn = sol[a[i]]
            if (sol[b[i]] < mn) 
                mn = sol[b[i]]
            if (mn != c[i]) 
                ok = 0
        }
        if (ok == 0) {
            println("NO")
        } else {
            println("YES")
            var print = ArrayList<Int>()
            for (i in 1..n) 
                print.add(sol[i])
            println(print.joinToString(" "))
        }
    }
}