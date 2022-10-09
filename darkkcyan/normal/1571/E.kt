import java.util.*

val print_deb = false
fun eprintln(s: String) {
    if (print_deb) System.err.println(s)
}

fun main() {
    for (testcase in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        var s = readLine()!!
        val a = readLine()!!
        
        val gr = Array(n + 2) { MutableList<Int>(0) {0} }
        val uo= n
        val uc = n + 1
        for ((i, ch) in a.withIndex()) {
            if (ch == '0') continue
            gr[uc].add(i)
            gr[i].add(uc)
            gr[uo].add(i + 3)
            gr[i + 3].add(uo)
            gr[i + 1].add(i + 2)
            gr[i + 2].add(i + 1)
        }
        
        val vis = IntArray(n + 2) {10 * n}
        val color = IntArray(n + 2)
        var timer = 0
        
        s += "()"
        
        fun Boolean.toInt() = if (this) 1 else 0
        
        
        fun try_fill(src: Int, col: Int): Int {
            eprintln("src = $src")  
            ++timer
            var qu = LinkedList<Int>()
            qu.add(src)
            color[src] = col
            vis[src] = timer
            
            var cost: Int = (col != (s[src] == ')').toInt()).toInt()
            
            while (qu.size > 0) {
                val u = qu.first
                qu.removeFirst()
                eprintln("u = $u, col = ${color[u]}")  
                for (v in gr[u]) {
                    eprintln("v = $v")
                    if (vis[v] == timer) {
                        eprintln("v = $v, col_v = ${color[v]}")
                        if (color[u] == color[v]) return -1
                        continue
                    }
                    vis[v] = timer
                    color[v] = 1 - color[u]
                    cost += (color[v] != (s[v] == ')').toInt()).toInt()
                    qu.addLast(v)
                }
            }
            return cost
        }
        
        var ans = try_fill(uo, 0)
        if (ans == -1) {
            println("-1") 
            continue
        }
        if (vis[uc] != timer) {
            val t = try_fill(uc, 1)
            if (t == -1) {
                println("-1") 
                continue
            }
            ans += t
        } else if (color[uc] == 0) {
            println("-1")
            continue
        }
        
        for (i in 0 until n) {
            if (vis[i] <= timer) continue
            val x = try_fill(i, 0)
            val y = try_fill(i, 1)
            if (x == -1) {
                ans = -1
                break
            }
            eprintln("i = $i, x = $x, y = $y") 
            ans += x.coerceAtMost(y)
        }
        println(ans)
    }
}