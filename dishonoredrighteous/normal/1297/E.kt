private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readDouble() = readLn().toDouble()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }

fun solve() {
    var (n, k) = readInts()

    var g = ArrayList<HashSet<Int>>()
    for (i in 0 until n) {
        g.add(HashSet())
    }

    for (i in 0 until n - 1) {
        var (from, to) = readInts()
        g[from - 1].add(to - 1)
        g[to - 1].add(from - 1)
    }

    var allLeaves = ArrayList<Int>()
    var leaves = 0
    var root = 0
    for (i in 0 until n) {
        if (g[i].size == 1) {
            leaves += 1
            allLeaves.add(i)
        }
        if (g[i].size > g[root].size) {
            root = i
        }
    }

    if (k > leaves) {
        println("No")
        return
    }

    var inAns = ArrayList<Boolean>()
    for (i in 0 until n) {
        inAns.add(true)
    }

    for (i in 0 until allLeaves.size - k) {
        var v = allLeaves[i]
        while (g[v].size == 1) {
            var p = g[v].first()
            g[v].remove(p)
            g[p].remove(v)
            inAns[v] = false
            v = p
        }
    }

    println("Yes")
    var cnt = 0
    for (i in inAns) {
        if (i) {
            cnt += 1
        }
    }

    println(cnt)
    for (i in 0 until n) {
        if (inAns[i]) {
            print(i + 1)
            print(' ')
        }
    }
    println()
}

fun main(args: Array<String>) {
    var t = readInt()

    while (t > 0) {
        t -= 1
        solve()
    }
}