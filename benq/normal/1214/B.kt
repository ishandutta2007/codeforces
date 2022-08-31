import java.util.*

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextInts() = next().split(" ").map { it.toInt() }
fun nextLongs() = next().split(" ").map { it.toLong() }

fun solve() {
    val b = nextInt()
    val g = nextInt()
    val n = nextInt()
    var ans = 0
    for (i in 0..n) if (i <= b && n-i <= g) ans ++
    print(ans)
}

fun main(args: Array<String>) {
    val t = 1
    for (i in 0..t-1) solve()
}