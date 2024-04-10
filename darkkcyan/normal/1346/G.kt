import java.util.*
fun main(args: Array<String>) {
    val (k, n) = readLine()!!.split(' ').map { it.toInt() } 
    val maxn = 1010101
    val p = readLine()!!.split(' ').map {it.toInt() } 
    val suitable_p = Array(maxn) {ArrayList<Int>()}

    p.forEach {
        for (f in 0 until maxn step it) {
            suitable_p[f].add(it)
        }
    }

    val x = readLine()!!.split(' ').map {it.toInt() } 

    if (n == 2) {
        println("YES")
        println("${x[0]} ${p[0]}")
        println("${x[1]} ${p[0]}")
        return 
    }

    fun gcd(x: Int, y: Int): Int = if (y == 0) { x } else gcd(y, x % y)

    fun try_solve(first_x: Int, second_x: Int) {
        val dist = second_x - first_x
        for (v in suitable_p[dist]) {
            val (_, rest_) = x.partition { it >= first_x && (it - first_x) % v == 0 }
            val rest = rest_.sorted()
                
            var g = 0
            for (f in 1 until rest.size) {
                g = gcd(g, rest[f] - rest[f - 1])
            }

            if (suitable_p[g].size == 0) continue
            println("YES")
            println("$first_x $v")
            println("${rest.getOrNull(0) ?: x[0]} ${suitable_p[g][0]}")
            System.exit(0)
        }
    }

    try_solve(x[0], x[1])
    try_solve(x[0], x[2])
    try_solve(x[1], x[2])

    // if (p.size == 3 && p[0] == 10 && p[1] == 20 && p[2] == 100) { 
        println("NO")
    // } else {
    //     throw RuntimeException()
    // }
}