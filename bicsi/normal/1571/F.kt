fun main() {

    var (n, m) = readInts()
    var ans = IntArray(n) {0}

    var dp = Array(n + 1) {IntArray(m + 1) {0} }
    dp[0][0] = 1
    var sum = 0
    var ts = IntArray(n)
    var ks = IntArray(n)
    for (i in 0 until n) {
        var (ki, ti) = readInts()
        dp[i + 1] = dp[i].clone()
        if (ti == 1) {
            ans[i] = m - ki + 1
            m -= ki
        } else {
            for (j in 0 until m) {
                if (dp[i][j] == 1 && j + ki <= m) {
                    dp[i + 1][j + ki] = 1
                }
            }
            sum += ki
        }
        ts[i] = ti
        ks[i] = ki
    }
    if (m < 0) {
        println(-1)
        return
    }

//    for (i in 0 until n) {
//        println(dp[i].joinToString())
//    }

    for (i in 0 until m + 1) {
        if (dp[n][i] == 0) continue
        var m1 = m / 2
        var m2 = (m + 1) / 2
        if (m1 >= i && m2 >= (sum - i)) {
//            println("i=$i j=${sum-i} m1=$m1 m2=$m2")
            var bla = i
            for (j in (0 until n).reversed()) {
                assert(dp[j + 1][bla] == 1)
                if (ts[j] == 1) continue
                if (dp[j][bla] == 1) {
                    ans[j] = 2 * (m2 - ks[j] + 1) - 1
                    m2 -= ks[j]
                } else {
                    ans[j] = 2 * (m1 - ks[j] + 1)
                    m1 -= ks[j]
                    bla -= ks[j]
                }
            }
            assert(m1 >= 0)
            assert(m2 >= 0)

            println(ans.joinToString(" "))
            return
        }
    }

    println(-1)





}

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints