fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }

    val answer = IntArray(n)
    val a = IntArray(n)

    var total = m
    var sum = 0
    for (i in 0 until n) {
        val (k, t) = readLine()!!.split(" ").map { it.toInt() }
        if (t == 1) {
            answer[i] = total - k + 1
            total -= k
        } else {
            sum += k
            a[i] = k
        }
    }

    if (total < 0) {
        println(-1)
        return
    }

    val f = Array(5010) { BooleanArray(5000) }
    val g = Array(5010) { Array<Int?>(5000) { null } }
    var index = 0
    f[index][0] = true
    for (i in 0 until n) {
        if (a[i] == 0) continue
        ++index
        for (j in 0 until 5000) {
            if (f[index - 1][j]) {
                f[index][j] = true
            } else if (j >= a[i] && f[index - 1][j - a[i]]) {
                f[index][j] = true
                g[index][j] = i
            }
        }
    }

    var len = (0 until 5000).filter { f[index][it] }.filter { (sum - it) <= it }.minOrNull()

    if (len == null || 2 * len - 1 > total) {
        println(-1)
        return
    }

    var first = 1
    var second = 2
    while (index != 0) {
        val last = g[index][len]
        if (last != null) {
            answer[last] = first
            first += 2 * a[last]
            len -= a[last]
        }
        --index
    }

    println(answer.mapIndexed { index, value ->
        if (value == 0) {
            val tmp = second
            second += a[index] * 2
            tmp
        } else value
    }.joinToString(" "))
}