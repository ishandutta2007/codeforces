fun main() {
    for (testcase in 1..readLine()!!.toInt()) {
        val (n, s) = readLine()!!.split(' ').map{it.toLong()}

        fun ok(last: Long): Boolean {
            var cur = last
            var rest = s - last
            if (rest < 0) return false
            for (i in n - 2 downTo 0) {
                cur = (cur + 1) / 2
                rest -= cur
                if (rest < 0) return false
                if (cur == 1L) {
                    return rest >= i
                }
            }
            return true
        }

        var l = 1L
        var r = s
        while (l < r) {
            val mid = l + (r - l + 1) / 2
            if (ok(mid)) l = mid
            else r = mid - 1
        }
        println(l)
    }
}