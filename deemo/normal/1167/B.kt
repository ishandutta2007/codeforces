private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val ls = listOf(4, 8, 15, 16, 23, 42)
    val ans = mutableListOf<Int>()

    fun solve(a: Int, b: Int, c: Int) {
        println("? $a $b")
        val first = readInt()
        println("? $a $c")
        val second = readInt()

        for (x in ls)
            for (y in ls)
                for (z in ls)
                    if (setOf(x, y, z).size == 3 && (x*y == first && x*z == second)){
                        ans.addAll(listOf(x, y, z))
                        return
                    }
    }

    for (w in 1..4 step 3)
        solve(w, w+1, w+2)

    println(ans.joinToString(" ", prefix = "! "))
}