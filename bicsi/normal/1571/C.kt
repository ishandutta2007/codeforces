fun main() {

    var t = readInt()
    while (t-- > 0) {
        var n = readInt()
        var maxk = 10000000
        var mink = 0
        for (i in 0 until n) {
            var (a, b, s) = readLn().split(' ')
            var l = Math.min(a.length, b.length)
            var lcs = 0
            for (i in 0 until l) {
                if (a[a.length - i - 1] != b[b.length - i - 1]) {
                    break
                }
                lcs += 1
            }
            if (s == "0") {
                mink = Math.max(mink, lcs + 1)
            } else {
                maxk = Math.min(maxk, lcs)
            }
        }
//        println("$mink $maxk")

        println(Math.max(maxk - mink + 1, 0))
        if (mink <= maxk) {
            for (i in mink..maxk) {
                print("$i ")
            }
            println()
        }
    }
}

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints