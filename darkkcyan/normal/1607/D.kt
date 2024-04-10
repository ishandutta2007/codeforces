fun main() {
    for (testcase in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        class Elm (var x: Int, var col: Char )
        val a = Array(n) { Elm(0, 'a') }
        readLine()!!.split(' ').forEachIndexed { i, v -> a[i].x = v.toInt() }
        readLine()!!.forEachIndexed { i, v -> a[i].col = v }
        
        a.sortBy { it.x }
        
        var ok = true
        var r_pos = n
        for (i in n - 1 downTo 0) {
            if (a[i].col != 'R') continue
            if (a[i].x > r_pos) {
                ok = false
                break
            }
            --r_pos
        }
        var b_pos = 1
        for (i in 0 until n) {
            if (a[i].col != 'B') continue
            if (a[i].x < b_pos) {
                ok = false
                break
            }
            ++b_pos
        }
        if (ok) println("YES")
        else println("NO")
    }
}