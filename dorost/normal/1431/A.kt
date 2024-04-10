import java.util.*
import java.io.*
import kotlin.math.*

fun main() {
    var t = readLine()!!.toInt()
    while(t-->0) {
        solve()
    }
}
fun solve() {
    val l = readLine()!!.split(" ").map { it.toInt() }
    var n = l[0];
    val a = (readLine()!!.split(" ").map { it.toLong() }).toLongArray()
    a.sort()
    var ans = 0.toLong()
    for (i in 0 until n) {
        ans = max(ans, ((n - i) * a[i]))
    }
    println(ans)
}