import java.util.*

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextInts() = next().split(" ").map { it.toInt() }
fun nextLongs() = next().split(" ").map { it.toLong() }

fun solve() {
    val n = nextInt()
    val d = nextInt()
    val e = 5*nextInt()
    var ans = n
    for (i in 0..d-1) {
        val tmp = n-e*i
        if (tmp < 0) break
        ans = minOf(ans,tmp%d)
    }
    print(ans)
}

fun main(args: Array<String>) {
    val t = 1
    for (i in 0..t-1) solve()
}