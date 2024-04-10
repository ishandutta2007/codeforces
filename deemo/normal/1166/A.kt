private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val n = readInt()
    val cnt = mutableMapOf<Char, Int>()
    repeat(n) {
        val s = readLn()
        cnt[s[0]] = if (!cnt.containsKey(s[0])) 1 else cnt[s[0]]!! + 1
    }

    var ans = 0L
    for ((a, b) in cnt) {
        val x = b/2
        val y = (b+1)/ 2
        ans += 1L*x*(x-1)/ 2
        ans += 1L*y*(y-1)/ 2
    }
    println(ans)
}