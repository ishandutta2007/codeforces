fun main() {
    for (testcase in 1..readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map{it.toInt()}
        class Robot(var pos: Int, var dir: Char, val id: Int)
        val a = Array(n) { Robot(0, 'x', it) }
        readLine()!!.split(' ').forEachIndexed { i, v -> a[i].pos = v.toInt() }
        readLine()!!.split(' ').forEachIndexed { i, v -> a[i].dir = v[0] }
        a.sortBy { it.pos }
        
        val ans = IntArray(n) {-1}
        
        val stk = Array(2) { MutableList(0) { Robot(0, ' ', -1) }}
        
        for (i in 0 until n) {
            val the_stk = stk[a[i].pos % 2]
            if (the_stk.size == 0) {
                the_stk.add(a[i])
                continue
            }
            if (the_stk.last().dir == 'R' && a[i].dir == 'L') {
                val lst = the_stk.removeLast()
                val cur_ans = (a[i].pos - lst.pos) / 2
                ans[a[i].id] = cur_ans
                ans[lst.id] = cur_ans
                continue
            }
            if (the_stk.last().dir == 'L' && a[i].dir == 'L') {
                val lst = the_stk.removeLast()
                val cur_ans = (a[i].pos + lst.pos) / 2
                ans[a[i].id] = cur_ans
                ans[lst.id] = cur_ans
                continue
            }
            the_stk.add(a[i])
        }
        
        for (the_stk in stk) {
            while (the_stk.size >= 2) {
                val u = the_stk.removeLast()
                val v = the_stk.removeLast()
                assert(u.dir == 'R')
                if (v.dir == 'R') {
                    val cur_ans = (2 * m - u.pos - v.pos) / 2
                    ans[u.id] = cur_ans
                    ans[v.id] = cur_ans
                } else {
                    val cur_ans = (2 * m + v.pos - u.pos) / 2
                    ans[u.id] = cur_ans
                    ans[v.id] = cur_ans
                }
            }
        }
        println(ans.joinToString(" "))
    }
}