private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun solve(a: MutableList<Int>): IntArray {
    val n = a.size
    var sum = 0
    for(i in 0 until n){
        sum += a[i]
    }

    var res = IntArray(n)

    var dp = Array(n + 1) {IntArray(sum + 1)}
    for(i in 0..n){
        for(j in 0..sum){
            dp[i][j] = -1
        }
    }

    dp[0][0] = 1
    for(i in 0 until n){
        for(j in 0 until sum){
            if (dp[i][j] != -1){
                dp[i + 1][j + a[i]] = 1
                dp[i + 1][j] = 0
            }
        }
    }

    var tut = -1
    var shar = n
    for(i in 0..sum) if (i >= sum - i && dp[n][i] != -1) {
        tut = i
        break
    }

    while(shar > 0){
        res[shar - 1] = dp[shar][tut]
        if (dp[shar][tut] == 1) tut -= a[shar - 1]
        shar--
    }

    /*for(i in res){
        print("$i ")
    }
    println()*/
    return res
}

fun main(){
    val (n, m) = readInts()
    var data = Array(n) {IntArray(2)}
    for(i in 0 until n){
        data[i] = readInts().toIntArray()
    }

    var totSum = 0
    for(i in 0 until n){
        totSum += data[i][0]
    }

    if (totSum > m){
        println(-1)
        return
    }

    var ans = IntArray(n)
    var start = 0
    for(i in 0 until n){
        if (data[i][1] == 1){
            ans[i] = start
            start += data[i][0]
        }
    }

    var list: MutableList<Int> = mutableListOf()
    for(i in 0 until n){
        if (data[i][1] == 2){
            list.add(data[i][0])
        }
    }

    val res = solve(list)
    var start_even = start
    var start_odd = start + 1
    var id = 0
    for(i in 0 until n) {
        if (data[i][1] == 2) {
            if (res[id] == 1){
                ans[i] = start_even
                start_even += 2 * data[i][0]
            }else{
                ans[i] = start_odd
                start_odd += 2 * data[i][0]
            }
            id++
        }
    }

    var ok = true
    for(i in 0 until n){
        if (data[i][1] == 1){
            if (ans[i] + data[i][0] - 1 >= m) ok = false
        }else{
            if (ans[i] + data[i][0] * 2 - 2 >= m) ok = false
        }
    }

    if (!ok){
        println(-1)
    }else {
        for (i in 0 until n) {
            print("${ans[i] + 1} ")
        }
        println()
    }
}