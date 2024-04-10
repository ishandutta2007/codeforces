private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readDouble() = readLn().toDouble()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }

fun check(n: Int, k: Int, m: Int, a: List<Pair<Int, Int>>): Boolean {
    var cur = ArrayList<Pair<Int, Int>>()
    cur.add(Pair(a[n - 1].first + m, a[n - 1].second))
    var curK = k - m

    for (i in n - 2 downTo 0) {
        var shit = cur[cur.size - 1].first - a[i].first - 1

        if (shit > curK) {
            cur.add(Pair(a[i].first + curK, a[i].second))
            curK = 0
        } else {
            cur.add(Pair(a[i].first + shit, a[i].second))
            curK -= shit
        }
    }

    return curK == 0
}

fun solve() {
    var (n, k) = readInts()
    val a = ArrayList<Pair<Int, Int>>()

    var numbers = readStrings()
    for (i in 0 until n) {
        a.add(Pair(numbers[i].toInt(), i))
    }

    var sortedA = a.sortedWith(compareBy({it.first}, {it.second}))
//    println(sortedA)

    var l = -1
    var r = k
    while (r - l > 1) {
        var m = (l + r) / 2

        if (check(n, k, m, sortedA)) {
            r = m
        } else {
            l = m
        }
    }

    var ans = ArrayList<Int>()
    for (i in 0 until n) {
        ans.add(0)
    }

    var m = r
//    println(m)
//    println(n)
    var cur = ArrayList<Pair<Int, Int>>()
    cur.add(Pair(sortedA[n - 1].first + m, sortedA[n - 1].second))
    ans[sortedA[n - 1].second] = m
    var curK = k - m

    for (i in n - 2 downTo 0) {
//        println(cur[cur.size - 1])
//        println(sortedA[i])

        var shit = cur[cur.size - 1].first - sortedA[i].first - 1

        if (shit > curK) {
            cur.add(Pair(sortedA[i].first + curK, sortedA[i].second))
            ans[sortedA[i].second] = curK
            curK = 0
        } else {
            cur.add(Pair(sortedA[i].first + shit, sortedA[i].second))
            ans[sortedA[i].second] = shit
            curK -= shit
        }

//        print(shit)
//        print(' ')
    }

    for (i in ans) {
        print(i)
        print(' ')
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