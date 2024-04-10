import kotlin.math.max

fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!.trim()
    val parts = s.split(Regex("[^x]+")).map { max(it.length - 2, 0) }.sum()

    println(parts)
}