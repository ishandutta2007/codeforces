fun main() {

    var (n, m) = readInts()
    var (f0, l0) = readInts()
    var cnt1 = IntArray(n) {0}
    var cnt2 = IntArray(n) {0}
    var cnt3 = IntArray(n * n) {0}
    for (i in 1 until m) {
        var (fi, li) = readInts()
        cnt1[fi - 1] += 1
        cnt2[li - 1] += 1
        cnt3[(fi - 1) * n + (li - 1)] += 1
    }
    var best = 0
    for (f in (1..n)) {
        for (l in (1..n)) {
            if (f == f0 || l == l0 || f == l) continue
            val now = cnt1[f - 1] + cnt2[l - 1] - cnt3[(f - 1) * n + (l - 1)]
            if (best <= now) {
                best = now
            }
        }
    }
    println(best + 1)
}

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints