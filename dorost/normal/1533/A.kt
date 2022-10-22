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
    var k = l[1];
    var ans = 0
    for (i in 0 until (n)) {
        val a = readLine()!!.split(" ").map { it.toInt() }
        var x = a[0]
        var y = a[1]
        if (x < k) {
            x = k;
        }
        if (x <= k) {
            ans = max(ans, y - x + 1);
        }
    }
    println(ans);
}