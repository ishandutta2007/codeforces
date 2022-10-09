import java.util.*
import kotlin.collections.ArrayList

fun main() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)

    val a = Array(n) {
        readLine()!!.toCharArray().map { it.toInt() - 'A'.toInt() }
    }

    fun createMat(mask: Int): Array<IntArray> {
        val ans = Array(n) { IntArray(m) }
        for (i in 0 until n) {
            for (f in 0 until m) {
                if (((1 shl a[i][f]) and mask) > 0) {
                    ans[i][f] = 1
                }
            }
        }
        return ans
    }

    fun countOne(mat: Array<IntArray>): Long {
        var ans = 0L
        val h = IntArray(m) {0}
        val prev = IntArray(m)
        val next = IntArray(m)
        for (base in 0 until n) {
            for (i in 0 until m) {
                if (mat[base][i] == 0) {
                    h[i] = 0
                } else {
                    h[i]++
                }
            }

            val st = ArrayList<Int>()

            for (i in 0 until m) {
                while (st.size > 0 && h[st.last()] > h[i]) {
                    st.removeLast()
                }
                if (st.size == 0) {
                    prev[i] = -1
                } else {
                    prev[i] = st.last()
                }
                st.add(i)
            }

            st.clear()
            for (i in m - 1 downTo 0) {
                while (st.size > 0 && h[st.last()] >= h[i]) {
                    st.removeLast()
                }
                if (st.size == 0) {
                    next[i] = m
                } else {
                    next[i] = st.last()
                }
                st.add(i)
            }

            for (i in 0 until m) {
                val left = i - prev[i]
                val right = next[i] - i
                ans += left.toLong() * right.toLong() * h[i].toLong()
            }
        }
        return ans
    }

    fun choose2(x: Long): Long {
        return x * (x + 1) / 2
    }

    val all = choose2(n.toLong()) * choose2(m.toLong())

    var popCount = IntArray(32)
    var paritySign  = IntArray(32)
    paritySign[0] = -1
    for (i in 1 until popCount.size) {
        val firstBit = i and (-i)
        popCount[i] = popCount[i - firstBit] + 1
        paritySign[i] = paritySign[i - firstBit] * (-1)
    }

    var dp = LongArray(32) {
        countOne(createMat(it)) * paritySign[it]
    }

    for (bit in 0..4) {
        for (i in 0 until dp.size) {
            val f = i xor (1 shl bit)
            if (i > f) {
                dp[i] += dp[f]
            }
        }
    }

    val ans = LongArray(6)
    for (i in 0 until dp.size) {
        ans[popCount[i]] += Math.abs(dp[i])
    }

    for (i in 1..5) {
        print("${ans[i]} ")
    }
}