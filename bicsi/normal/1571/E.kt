fun main() {

    var t = readInt()
    while (t-- > 0) {
        var n = readInt()
        var s = readLn()
        var t = readLn()
        var strs = Array<String>(16) {""}
        val reg = IntArray(16){0}
        for (i in 0 until 16) {
            var bla = mutableListOf<Char>()
            for (j in 0 until 4) {
                var req = '(';
                if ((i and (1 shl j)) != 0) {
                    req = ')'
                }
                bla.add(req)
            }
            val bla2 = bla.joinToString("")
            strs[i] = bla2
            if (bla2 == "(())" || bla2 == "()()") {
                reg[i] = 1
            }
        }
//        for (str in strs) {
//            println(str)
//        }

        var dp = IntArray(16) {0}
        var ndp = IntArray(16) {0}
        for (i in 0 until 16) {
            val str = strs[i]
            for (j in 0 until 4) {
                if (str[j] != s[j]) {
                    dp[i] += 1
                }
            }
//            println("$str, $s, ${dp[i]}")
        }
        for (i in 0 until t.length) {
//            println(dp.joinToString(" "))
            if (t[i] == '1') {
                for (j in 0 until 16) {
                    if (reg[j] == 0) {
                        dp[j] = 1000000000
                    }
                }
            }
            if (i + 1 < t.length) {
                var now = s[i + 4]
                for (j in 0 until 16) {
                    ndp[j] = 1000000000
                }
                for (j in 0 until 16) {
                    ndp[j / 2] = Math.min(ndp[j / 2], dp[j] + (if (now != '(') { 1}  else {0}))
                    ndp[j / 2 + 8] = Math.min(ndp[j / 2 + 8], dp[j] + (if (now != ')') {1} else {0}))
                }
                for (j in 0 until 16) {
                    dp[j] = ndp[j]
                }
            }
        }
        var best = 1000000000
        for (i in 0 until 16) {
            best = Math.min(best, dp[i])
        }
        if (best <= n) {
            println(best)
        } else {
            println(-1)
        }
    }
}

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints