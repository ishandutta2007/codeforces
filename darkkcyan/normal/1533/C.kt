fun main() {
    val err = System.err
    for (testcase in 1..readLine()!!.toInt()) {
//        err.println("----")
        val (n, k) = readLine()!!.split(' ').map(String::toInt)
        val like = readLine()!!.toCharArray().map { it -> it.toInt() - '0'.toInt()}
        var likeCount = like.count { it == 1 }
        var idx = 0
        var ans = 0

        var next = IntArray(n) { (it + 1) % n }
        var prev = IntArray(n) { (it - 1 + n) % n}

        fun del(id: Int): Int {
            val nxt = next[id]
            val prv = prev[id]
            next[prv] = nxt
            prev[nxt] = prv
            return nxt
        }

        while (likeCount > 0)  {
//            err.println("$idx, ${like[idx]}")
            ans ++
            likeCount -= like[idx]
            idx = del(idx)
            for (i in 1 until k) idx = next[idx]
        }
        println(ans)
    }
}