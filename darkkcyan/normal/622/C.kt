import java.io.*
import java.util.*

fun main() {
    val bf = BufferedReader(InputStreamReader(System.`in`))
    var stk: StringTokenizer? = null
    fun next(): String {
        while (stk == null || !stk!!.hasMoreTokens()) {
            stk = StringTokenizer(bf.readLine()!!)
        }
        return stk!!.nextToken()!!
    }
    val n = next().toInt()
    val m = next().toInt()
    val a = IntArray(n) { next().toInt() }
    val next_neq = IntArray(n) {n}
    for (i in n - 2 downTo 0) {
        if (a[i] == a[i + 1]) next_neq[i] = next_neq[i + 1]
        else next_neq[i] = i + 1
    }
    
    println((sequence {
        for (qr in 0 until m) {
            val l = next().toInt()
            val r = next().toInt()
            val x = next().toInt()
            yield(
                if (a[l - 1] != x) l
                else if (next_neq[l - 1] < r) next_neq[l - 1] + 1
                else -1
            )
        }
    }).joinToString("\n"))
    
}