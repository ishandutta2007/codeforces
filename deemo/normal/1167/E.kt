import java.lang.Integer.max

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val (n, x) = readInts()
    val a = readInts()
    val mn = MutableList(x+1) {n+2}
    val mx = MutableList(x+1) {-1}

    for ((i, y) in a.withIndex()) {
        mx[y] = i
        if (mn[y] == n+2)
            mn[y] = i
    }

    var cur = n
    var r = x+1
    val sv = MutableList(x+1) {n+1}
    while (r > 1 && (mx[r-1] == -1 || mx[r-1] < cur)) {
        r--
        cur = if (mx[r] == -1) cur else mn[r]
        sv[r] = cur
    }

    var ans = (x-r+1).toLong()
    if (r == 1)
        ans--

    cur = -1
    for (l in 1 until x) {
        if (mn[l] < cur) break
        cur = max(cur, mx[l])
        while (l == r || (r < x+1 && cur >= sv[r])) r++
        ans += x-r+2
        if (l+1 == r)
            ans--
    }
    println(ans+1)
}