fun nextInt() = readLine()!!.toInt()
fun nextInts() = readLine()!!.split(" ").map { it.toInt() }

fun main(args: Array<String>) {
    val (y, b, r) = nextInts()
    print(3*minOf(r-1,b,y+1))
}