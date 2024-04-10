fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextInts() = next().split(" ").map { it.toInt() }

fun main(args: Array<String>) {
    val n = nextInt()
    val s = next().toSet()
    if (s.size < n || n == 1) print("Yes")
    else print("No")
}