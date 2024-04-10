private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readDouble() = readLn().toDouble()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }

fun solve() {
    var n = readInt()

    val events = ArrayList<Pair<Int, Int>>()
    for (i in 0 until n) {
        var (l, r) = readInts()
        events.add(Pair(l, +1))
        events.add(Pair(r + 1, -1))
    }
    val res = events.sortedWith(compareBy({it.first}, {it.second}))

//    for (q in res) {
//        print(q.first)
//        print(" ")
//        println(q.second)
//    }

//    var res = HashMap<Int, Int>()

    var opened = 0
    var prev = res[0].first
    var i = 0
    while (i < res.size) {
//        print(q.first)
//        print(" ")
//        print(q.second)
//        println()
        var cur = res[i].first
        while (i < res.size && res[i].first == cur) {
            opened += res[i].second
            i += 1
        }
        i -= 1

        if (opened == 1) {
            println(cur)
            return
        }

        i += 1
    }

    println(-1)
}

fun main(args: Array<String>) {
    var t = readInt()

    while (t > 0) {
        t -= 1
        solve()
    }
}