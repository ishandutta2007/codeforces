private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles




fun main(){

    val N = 1600000 + 666
    val INF = 1000000000000000000L
    var Fenwick = LongArray(N)
    for(i in 0 until N){
        Fenwick[i] = -INF
    }

    fun update(_pos: Int, value: Long){
        var pos = _pos
        while(pos < N){
            Fenwick[pos] = Math.max(Fenwick[pos], value)
            pos = pos or (pos + 1)
        }
    }

    fun get(_pos: Int): Long{
        var res = -INF
        var pos = _pos
        while(pos >= 0){
            res = Math.max(res, Fenwick[pos])
            pos = (pos and (pos + 1)) - 1
        }

        return res
    }

    val (n, m) = readInts()
    var ans = 0L

    update(N / 2 + m, 0L)

    var all: MutableList<Triple<Int, Int, Int>> = mutableListOf()

    for(it in 1..n) {
        val k = readInt()
        val a = readInts()
        val b = readInts()
        for (i in 0 until k) {
            all.add(Triple<Int, Int, Int>(it, a[i], b[i]))
        }
    }

    all.sortBy { -it.third }

    for(i in 0 until all.size) {
        val tut = all[i]
        val dp = tut.second + get(N / 2 + tut.third + tut.first - 1)
        ans = Math.max(ans, dp)
        update(N / 2 + tut.third + tut.first, dp)
    }

    println(ans)
}