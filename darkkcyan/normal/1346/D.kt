import java.util.*

fun main(args: Array<String>) {
    for (testcase in 1..readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map { it.toInt() } 
        val vals = IntArray(n) {0}
        val edges = Array<Triple<Int, Int, Int>>(m) { 
            var (u, v, c) = readLine()!!.split(' ').map { it.toInt() } 
            u -= 1
            v -= 1
            vals[u] = Math.max(vals[u], c)
            vals[v] = Math.max(vals[v], c)
            Triple(u, v, c)
        }

        val has_ans = edges.all { it.third == Math.min(vals[it.first], vals[it.second]) }
        if (!has_ans) {
            println("NO")
        } else {
            println("YES")
            println(vals.joinToString(" "))
        }
    }
}