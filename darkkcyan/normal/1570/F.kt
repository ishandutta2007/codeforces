fun main() {
    val (n, m) = readLine()!!.split(' ').map {it.toInt()}
    val a = Array(n) { readLine()!!.split(' ').map {it.toInt()}.toIntArray() }
    val b = Array(n) { IntArray(m) }
    
    val ans = MutableList<Pair<Int, Int>>(0) { 0 to 0 }
    
    fun do_op(r: Int, c: Int) { 
        ans.add(r to c)
        b[r][c] = 1
        b[r + 1][c] = 1
        b[r][c + 1] = 1
        b[r + 1][c + 1] = 1
    }
    
    for (i in 0 until n - 1) {
        for (f in 0 until m - 1) {
            if (a[i][f] == 1 && a[i + 1][f] == 1 && a[i][f + 1] == 1 && a[i + 1][f + 1] == 1) {
                do_op(i, f)
            }
        }
    }
    if (a contentDeepEquals b) {
        println(ans.size)
        for ((r, c) in ans) {
            println("${r + 1} ${c + 1}")
        }
    } else {
        println("-1")
    }
}