import kotlin.math.max

/*
Dynamic programming: f[i][j] = max( f[i - 1][j]             // skip
                                    f[i - 1][j + 1]         // destroy one
                                    f[i - 1][j] + a[i][k] ) // if b[i][k] == j

            0    ...    m
          j
       0               o
                       
                     o o
         
       .           o o o
       . 
       .         o o o o
                       
               o o o o o
                   
             o o o o o o
                 
       n   o o o o o o o
         
         
         i

From the above drawing, we can do DP for all meaningful transitions (attacks in the code) in the increasing order of
tuple (b, i, a). In other words, from the right to the left, and from the top to the bottom.

We store the max value of each diagonal line (0-indexed start from the main diagonal line), and use BIT to keep track 
of the prefix maximum value. 
 */

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }

    val attacks = mutableListOf<Triple<Int, Int, Int>>()
    for (i in 1..n) {
        readLine()
        val a = readLine()!!.split(" ").map { it.toInt() }
        val b = readLine()!!.split(" ").map { it.toInt() }
        for ((_a, _b) in (a zip b).asReversed()) {
            if (_b + i - 1 < m) break
            attacks.add(Triple(_b, i, _a))
        }
    }

    attacks.sortWith(compareBy({ -it.first }, { it.second }, { it.third }))

    var answer: Long = 0

    val f = LongArray(n + 10)
    for ((b, i, a) in attacks) {
        val index = i - (m - b)
        var now = 0L

        // query BIT
        var j = index - 1
        while (j >= 0) {
            now = max(now, f[j])
            j = (j and (j + 1)) - 1
        }

        now += a
        answer = max(answer, now)

        // update BIT
        j = index
        while (j < n + 10) {
            f[j] = max(f[j], now)
            j = j or (j + 1)
        }
    }

    println(answer)
}