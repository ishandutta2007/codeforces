tailrec fun removeZeroes(x: Int): Int =
        if (x % 10 == 0) removeZeroes(x / 10) else x
fun f(x: Int) = removeZeroes(x + 1)

fun main() {
    var n = readLine()!!.toInt()
    var reached = HashSet<Int>()
    while (reached.add(n))
        n = f(n)
    println(reached.size)
}