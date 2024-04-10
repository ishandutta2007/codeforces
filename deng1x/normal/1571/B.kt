import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val (a, va) = readLine()!!.split(" ").map { it.toInt() }
        val (_, vc) = readLine()!!.split(" ").map { it.toInt() }
        val b = readLine()!!.toInt()
        println(min(vc, b - a + va))
    }
}