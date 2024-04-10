private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double

private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of long
private fun readDoubles() = readStrings().map { it.toDouble() } // list of double

private val OL = mutableListOf<String>()
private fun addOL(s: String){
    OL.add(s)
}
private fun outputRes() {
    println(OL.joinToString("\n"))
}

private val MAXN = 1e5.toInt()
private val MOD = 1e9.toInt() + 7

private fun getDivisors(m: Int): MutableList<Int> {
    val res = mutableListOf<Int>()
    var i = 1
    while (i * i <= m) {
        if (m % i == 0) {
            res.add(i)
            if (m/i != i)
                res.add(m/i)
        }
        i++
    }
    return res
}

fun main() {
    var (m, k) = readInts()
    val divs = getDivisors(m).sorted()

    val mp = HashMap<Int, Int>()
    val divCount = divs.size
    for (i in 0 until divCount)
        mp[divs[i]] = i


    val flag = m < 10
    val vis = Array(if (flag) 1e5.toInt() else 2000) { BooleanArray(if (flag) 10 else 5000) }
    val dp = Array(if (flag) 1e5.toInt() else 2000) { Array(if (flag) 10 else 5000) {0L} }

    val zz = mutableListOf<Char>()
    fun get(ln: Int, target: Int, count: Int): Pair<Boolean, String> {
        if (ln == 0) {
            if (target != 0)
                return false to "0"
            dp[ln][target] = 1
            if (count == 1)
                return true to ""
            return false to "1"
        }

        var c = count
        if (vis[ln][target]) {
            if (count == 0)
                return false to ""
            if (dp[ln][target] < c)
                return false to dp[ln][target].toString()

            for (first in 1..9)
                if (divs[target] % first == 0) {
                    val ans = get(ln-1, mp[divs[target]/ first]!!, c)
                    if (ans.first) {
                        zz.add((first + 48).toChar())
                        return true to ""
                    }

                    c -= ans.second.toInt()
                }
            assert(false)
        }

        vis[ln][target] = true
        for (first in 1..9)
            if (divs[target]%first == 0) {
                get(ln-1, mp[divs[target]/ first]!!, 0)
                dp[ln][target] += dp[ln-1][mp[divs[target]/ first]!!]
            }
        return get(ln, target, count)
    }

    var temp = m
    for (d in 2..9)
        while (temp % d == 0)
            temp /= d
    if (temp > 1) {
        println(-1)
        return
    }

    for (ln in 1 until 100000) {
        for (first in 1..9)
            if (m % first == 0) {
                val ans = get(ln-1, mp[m/first]!!, k)
                if (ans.first) {
                    zz.add((first + 48).toChar())
                    zz.reverse()
                    println(zz.joinToString(""))

                    return
                }

                k -= ans.second.toInt()
            }
    }
}