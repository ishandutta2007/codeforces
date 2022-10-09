fun main(args: Array<String>) {
    for (testcase in 1 .. readLine()!!.toInt()) {
        val (h, c, t) = readLine()!!.split(' ').map { it.toLong() }
        var ans = 1L
        fun update_ans(x_: Long) {
            val x = Math.abs(x_)
            if (x == 0L) return ;
            val sum_ans = Math.abs((ans + 1) / 2 * h + ans / 2 * c - t * ans)
            val sum_x = Math.abs((x + 1) / 2 * h + x / 2 * c - t * x)
            // System.err.println("$x $t $sum_ans $sum_x ${sum_ans * 1.0 / ans} ${sum_x * 1.0 / x}") 

            if (sum_x * ans < sum_ans * x) {
                ans = x
            } else if (sum_x * ans == sum_ans * x) {
                ans = Math.min(ans, x)
            }
        }

        update_ans(2)
        val rest = 2 * t - h - c
        if (rest != 0L) {
            val x = (h - c) / rest
            for (i in x - 2..x + 2) {
                update_ans(i)
            }
        }
        println(ans)
    }
}