import kotlin.math.max

fun main() {
    for (testcase in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }.toList()

        val pos = IntArray(n + 1) { - 1 }

        val bit = IntArray(n + 10)
        fun upd(id: Int, v: Int) {
            var i = id + 1
            while (i < bit.size) {
                bit[i] = max(bit[i], v)
                i += i and (-i)
            }
        }

        fun get(id: Int): Int {
            var ans = 0
            var i = id + 1
            while (i > 0) {
                ans = max(ans, bit[i])
                i -= i and (-i)
            }
            return ans
        }

        var ans = 0
        for ((i, v) in a.withIndex()) {
            if (pos[v] == -1) {
                pos[v] = i
                ans = max(ans, 1)
                upd(n - i, 1)
                continue
            }
            val curAns = get(n - pos[v] - 1) + 2
            ans = max(ans, curAns)
            upd(n - pos[v], curAns)
            ans = max(ans, 1)
            upd(n - i, 1)
        }
        println(ans)
    }
}