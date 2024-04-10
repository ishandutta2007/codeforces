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
        var (n, k, x, y) = readInts()
        var input = readInts()
        var sum = 0L
        for (i in 0..n - 1) 
            sum += input[i].toLong()
        var forSorting = ArrayList<Pair<Int, Int>>()
        for (i in 0..n - 1) 
            forSorting.add(Pair(input[i], 0))
        forSorting.sortWith(compareBy({it.first},{it.second}))
        var sol = 0L
        for (i in 0..n - 1) {
            if (forSorting[i].first > k)
                sol += x
        }
        for (cnt in 0..n) {
            var now = x.toLong() * cnt + y
            var mx = 0L
            if (sum % n.toLong() == 0L)
                mx = sum / n.toLong()
            else
                mx = sum / n.toLong() + 1L
            if (cnt == n)
                break
            sum -= forSorting[n - cnt - 1].first
            if (mx <= k)
                if (now < sol) 
                    sol = now
        }
        println(sol)
    }
}