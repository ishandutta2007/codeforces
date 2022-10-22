private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt()-1 } // list of ints

fun main() {
    var (n, a, x, b, y) = readInts()
    b = y.also{y = b}

    fun dist(a: Int, b: Int) = if (a <= b) b-a else (n+1)-(a-b)
    for (i in 0..n)
        if (dist(a, i) + dist(i, x) == dist(a, x))
            if (dist(b, i) + dist(i, y) == dist(b, y))
                if (dist(a, i) == dist(i, y)) {
                    println("YES")
                    return
                }
    println("NO")
}