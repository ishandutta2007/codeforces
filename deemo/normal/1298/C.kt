private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double

private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of long
private fun readDoubles() = readStrings().map { it.toDouble() } // list of double

private val OL = mutableListOf<String>()
private fun addOL(s: String){
    OL.add(s)
}
private fun outputRes() {
    println(OL.joinToString("\n"))
}

private val MAXN = 1e5.toInt()
private val MOD = 1e9.toInt() + 7

fun main() {
    val n = readInt()
    val s = readLn()
    assert(n == s.length)
    var l = 0
    var ans = 0
    while (l < n) {
        if (s[l] != 'x') {
            l++;
            continue;
        }

        var r = l
        while (r < n && s[r] == 'x') r++;

        ans += maxOf(0, r-l-2)

        l = r;
    }
    println(ans)
}