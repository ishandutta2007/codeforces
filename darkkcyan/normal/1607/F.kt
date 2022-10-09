fun main() {
    for (testcase in 1..readLine()!!.toInt()) {
        readLine()!!
        val (n, m) = readLine()!!.split(' ').map {it.toInt()}
        val board = Array(n) { readLine()!!.toCharArray() }
        val dist = Array(n) {IntArray(m) { -1 }}
        val vis = Array(n) { IntArray(m) { 0 }}
        
        fun isValid(r: Int, c: Int) = r >= 0 && r < n && c >= 0 && c < m
        
        class Pos(var r: Int, var c: Int) {
            fun next() {
                when (board[r][c]) {
                    'L' -> --c
                    'R' -> ++c
                    'U' -> --r
                    'D' -> ++r
                }
            }
            
            fun isValid() = r >= 0 && c >= 0 && r < n && c < m
            
            override operator fun equals(other: Any?) = 
                if (other == null) false
                else if (other !is Pos) false
                else r == other.r && c == other.c
        }
        
        fun getDist(r: Int, c: Int): Int {
            if (vis[r][c] != 0) return dist[r][c]
            val trace = MutableList(0) { Pos(0, 0) }
            var p = Pos(r, c)
            while (isValid(p.r, p.c) && vis[p.r][p.c] == 0) {
                trace.add(Pos(p.r, p.c))
                vis[p.r][p.c] = 1
                p.next()
            }
            if (!p.isValid() || vis[p.r][p.c] == 2) {
                val destDist = if (p.isValid()) dist[p.r][p.c] else 0 
                for ((i, cur) in trace.withIndex()) {
                    dist[cur.r][cur.c] = trace.size - i + destDist
                    vis[cur.r][cur.c] = 2
                }
                return dist[trace[0].r][trace[0].c]
            }
            
            var t = 0
            while (trace[t] != p) ++t
            for (i in t until trace.size) {
                val cur = trace[i]
                dist[cur.r][cur.c] = trace.size - t
                vis[cur.r][cur.c] = 2
            }
            for (i in 0 until t) {
                val cur = trace[i]
                dist[cur.r][cur.c] = trace.size - i
                vis[cur.r][cur.c] = 2
            }
            return dist[trace[0].r][trace[0].c]
        }
            
        data class AnsT(val d: Int, val r: Int, val c: Int): Comparable<AnsT> {
            override fun compareTo(other: AnsT) = d.compareTo(other.d)
        }
        
        var ans = AnsT(-1, -1, -1)
        for (i in 0 until n)
        for (f in 0 until m) {
            ans = ans.coerceAtLeast(AnsT(getDist(i, f), i, f))
        }
        println("${ans.r + 1} ${ans.c + 1} ${ans.d}")
    }
}