import kotlin.collections.set
import java.util.*
import java.lang.String

fun main(args: Array<String>) {
    val q = readLine()!!.toInt()
    for (z in 1..q) {
        val lst = readLine()!!.split(' ')
        val n = lst[0].toInt()
        val m = lst[1].toInt()
        val p = lst[2].toInt()
        var res = false
        for (i in 1..n) {
            if (p % i == 0 && p / i <= m) {
                res = true
            }
        }
        println(if (res) "Yes" else "No")
    }
}