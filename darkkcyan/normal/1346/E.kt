fun main(args: Array<String>) {
    val (n, m, k) = readLine()!!.split(' ').map {it.toInt()} 
    val ans = IntArray(n) { m + 10 }
    ans[k - 1] = 0
    for (i in 1 .. m) {
        val (u, v) = readLine()!!.split(' ').map { it.toInt() - 1}
        val new_ans_u = Math.min(ans[u] + 1, ans[v])
        val new_ans_v = Math.min(ans[u], ans[v] + 1)
        ans[u] = new_ans_u
        ans[v] = new_ans_v
    }

    println(ans.map { if (it <= m) { it } else { -1 }}.joinToString(" "))
}