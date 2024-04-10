import java.util.*

fun main() {
    var n = readLine()!!.toLong()
    fun f(x_: Long): Long {
        var x = x_ + 1
        while (x % 10 == 0L) x /= 10
        return x
    }
    
    val se = TreeSet<Long>()
    while (!se.contains(n)) {
        se.add(n)
        n = f(n)
    }
    println(se.size)
}