fun main() {
    val err = System.err
    val s = readLine()!!.toCharArray().map { it.toInt() - '0'.toInt() }
    val n = s.size

    val changedPos = Array(2) { IntArray(n + 1) }

    val cnt = Array(n + 1) { IntArray(2) }
    for (i in 0 until n) {
        cnt[i].copyInto(cnt[i + 1])
        cnt[i + 1][s[i]]++
        changedPos[s[i]][cnt[i + 1][s[i]]] = i
    }

    val total = cnt[n]

    fun minPartition(k: Int): Int {
//        err.println("-----")
//        err.println("k = $k")
        var ans = 0
        var i = 0
        while (i < n) {
            ans ++
            var nextPos = i
            for (chr in 0..1) {
                var curCnt = cnt[i][chr]
                var nextCnt = curCnt + k
                if (nextCnt >= total[chr]) {
                    nextPos = n
                    break
                }
                var curNextPos = changedPos[chr][nextCnt + 1]
                nextPos = Math.max(nextPos, curNextPos)
            }
//            err.println("k = $k, i = $i, nextPos = $nextPos")
            i = nextPos
        }
        return ans
    }

    for (i in 1 .. n) {
        val curAns = minPartition(i)
        print("$curAns ")
    }
}