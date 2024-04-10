fun main() {

    var t = readInt()
    while (t-- > 0) {
        var s = readLn()
        var cc = '='
        var bad = 0
        for (c in s.toCharArray()) {
            if (c == '=') continue
            if (cc == '=') cc = c
            if (c != cc) {
                bad = 1
            }
        }
        if (bad == 1) {
            println('?')
        } else {
            println(cc)
        }
    }
}

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints