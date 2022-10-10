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
    val a = ArrayList<Pair<Int, Int>>()

    var numbers = readStrings()
    for (i in 0 until n) {
        a.add(Pair(numbers[i].toInt(), i))
    }

    val res = a.sortedWith(compareBy({it.first}, {it.second}))

//    println(res)

    var positive = 0
    while (res[positive].first <= 0) {
        positive += 1
    }

    var max = 0
    for (i in positive until n) {
        max += res[i].first
    }

    var negative = 0
    while (res[negative].first < 0) {
        negative += 1
    }
    negative -= 1

//    println(max)

    var type1 = 0
    var type2 = 0

    for (i in positive + 1 until n) {
        type1 += res[i].first
    }
    if (negative != -1) {
        type2 = max + res[negative].first
    }

    var s = ArrayList<Char>()
    for (i in 0 until n) {
        s.add('0')
    }
    if (type1 > type2) {
        for (i in positive + 1 until n) {
            s[res[i].second] = '1'
        }
        println(type1)
    } else {
        for (i in positive until n) {
            s[res[i].second] = '1'
        }
        s[res[negative].second] = '1'
        println(type2)
    }

    for (i in s) {
        print(i)
    }
    println()
//    println(s.toString())
}

fun main(args: Array<String>) {
    var t = readInt()

    while (t > 0) {
        t -= 1
        solve()
    }
}