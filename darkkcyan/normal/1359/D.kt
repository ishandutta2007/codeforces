fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map{it.toInt()}.toIntArray()
    var ans = 0
    for (x in -30..30) {
        val max_pref_sum = IntArray(n) {0}
        val max_suff_sum = IntArray(n) {0}
        
        var s = 0
        for (i in 1 until n) {
            if (a[i - 1] <= x) {
                s += a[i - 1]
            } else {
                s = 0
            }
            s = Math.max(s, 0)
            max_pref_sum[i] = s
        }
        s = 0
        for (i in n - 2 downTo 0) {
            if (a[i + 1] <= x) {
                s += a[i + 1]
            } else {
                s = 0
            }
            s = Math.max(s, 0)
            max_suff_sum[i] = s
        }
        for (i in 0 until n) {
            if (a[i] == x) {
                ans = Math.max(ans, max_pref_sum[i] + max_suff_sum[i])
            }
        }
    }
    println(ans)
}