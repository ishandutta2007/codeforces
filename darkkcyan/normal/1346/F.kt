fun main(args: Array<String>) {
    val (n, m, q) = readLine()!!.split(' ').map { it.toInt() } 
    val a = Array(n) {
        readLine()!!.split(' ').map { it.toLong()}.toLongArray()
    }

    val row_sum = LongArray(n) { a[it].sum() }
    val col_sum = LongArray(m) { c -> a.map { it[c] }.sum() }

    fun get_min_val(dimen: LongArray): Long {
        if (dimen.size <= 1) return 0L
        var rSumId = dimen.mapIndexed { idx, v -> idx * v}.sum()
        var rSum = dimen.sum()
        var lSumId = 0L
        var lSum = 0L
        var ans = Long.MAX_VALUE

        for ((i, v) in dimen.withIndex()) {
            rSumId -= i * v
            rSum -= v
            val cur = (lSum * i - lSumId) + (rSumId - rSum * i)
            // System.err.println("$i $cur $lSum $rSum $lSumId $rSumId")
            ans = Math.min(ans, cur)
            lSumId += i * v
            lSum += v
        }
        return ans
    }

    fun get_ans(): Long = get_min_val(row_sum) + get_min_val(col_sum)

    val ans = LongArray(q + 1)
    ans[0] = get_ans()
    for (i in 1 .. q) {
        var (x, y, z) = readLine()!!.split(' ').map{it.toInt()} 
        x -= 1; y -= 1;
        row_sum[x] -= a[x][y]
        col_sum[y] -= a[x][y]
        a[x][y] = z.toLong()
        row_sum[x] += a[x][y]
        col_sum[y] += a[x][y]
        ans[i] = get_ans()
    }
    print(ans.joinToString(" "))
}