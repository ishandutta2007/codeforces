import kotlin.system.exitProcess

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private fun success() {
    println("YES")
    exitProcess(0)
}

fun main() {
    val (m, n) = readInts()
    val a = ArrayList<List<Int>>()
    for (i in 0 until n)
        a.add(readInts())

    fun go(x: Int, y: Int): Boolean {
        for (p in a)
            if (!p.toSet().contains(x) && !p.toSet().contains(y))
                return false
        return true
    }

    for (w in 0..1) {
        val x = a[0][w]
        var failed = false
        for (p in a)
            if (x != p[0] && x != p[1]) {
                if (go(x, p[0]) || go(x, p[1]))
                    success()
                failed = true
                break
            }
        if (!failed)
            success()
    }
    println("NO")
}