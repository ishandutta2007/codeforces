fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextInts() = next().split(" ").map { it.toInt() }

fun main(args: Array<String>) {
    val t = nextInt()
    for (i in 0..t-1) {
        var a = StringBuilder(next())
        var allSame = true
        for (j in 0..a.length-1) if (a[j] != a[0]) {
            allSame = false
            val c = a[a.length-1]; a[a.length-1] = a[j]; a[j] = c
            println(a)
            break
        }
        if (allSame) println(-1)
    }
}