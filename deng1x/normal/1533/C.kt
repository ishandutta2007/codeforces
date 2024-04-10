fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val mark = readLine()!!

        val next = IntArray(n)
        val prev = IntArray(n)
        for (i in 0 until n) {
            next[i] = (i + 1) % n
            prev[next[i]] = i
        }

        var total = mark.count { it == '1' }
        var ans = 0
        var now = 0
        while (total != 0) {
            ++ans
            if (mark[now] == '1') --total
            next[prev[now]] = next[now]
            prev[next[now]] = prev[now]

            repeat(k) {
                now = next[now]
            }
        }

        println(ans)
    }
}