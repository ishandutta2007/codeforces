fun main() {
    val dr = listOf(-1, 0, 1, 0)
    val dc = listOf(0, -1, 0, 1)

    for (testcase in 1..readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map(String::toInt)
        val board = Array(n) { readLine()!!.split(' ').map(String::toInt) }
        val eulerTour = MutableList(0) {0}
        val vis = Array(n) { BooleanArray(m) }

        fun dfs(r: Int, c: Int) {
            if (vis[r][c]) {
                return
            }
            vis[r][c] = true
            eulerTour.add(board[r][c])
            for (dir in 0..3) {
                val nr = r + dr[dir]
                val nc = c + dc[dir]
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                    continue
                }
                if (board[nr][nc] == 0) {
                    continue
                }
                if (vis[nr][nc]) {
                    continue
                }
                dfs(nr, nc)
                eulerTour.add(board[r][c])
            }
        }

        var ok = true
        for (i in 0 until n) {
            for (f in 0 until m) {
                if (board[i][f] == 0)  continue
                if (vis[i][f]) continue
                if (eulerTour.size > 0) {
                    ok = false
                    break
                }
                dfs(i, f)
            }
        }

        if (!ok) {
            println("-1")
            continue
        }

        val k = (eulerTour.size + 1) / 2
        println("$k $k")
        for (start in 0 until k) {
            println(eulerTour.subList(start, start + k).joinToString(" "))
        }
    }
}