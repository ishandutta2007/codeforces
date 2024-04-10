fun main() {
    var (n, m) = readInts()
    var A = Array (n) { readInts().toIntArray() }
    val B = Array(n) { IntArray(m) }
    val ops = mutableListOf<Pair<Int, Int>>()

    for (i in 1 until n) {
        for (j in 1 until m) {
            if (A[i][j] == 1 && A[i][j - 1] == 1 && A[i - 1][j] == 1 && A[i - 1][j - 1] == 1) {
                B[i][j] = 1
                B[i][j - 1] = 1
                B[i - 1][j] = 1
                B[i - 1][j - 1] = 1
                ops.add(Pair(i, j))
            }
        }
    }
    if (A.contentDeepEquals(B)) {
        println(ops.size)
        for ((a, b) in ops) {
            println("$a $b")
        }
    } else {
        println(-1)
    }
}

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints