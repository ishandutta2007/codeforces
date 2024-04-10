fun main() {

    var t = readInt()
    while (t-- > 0) {
        var n = readInt()
        var (a, va) = readInts()
        var (c, vc) = readInts()
        var b = readInt()
        for (vb in (va..(vc + 1))) {
            if (vb - va <= b - a && vc - vb <= c - b) {
                println(vb)
                break
            }
        }

    }
}

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints