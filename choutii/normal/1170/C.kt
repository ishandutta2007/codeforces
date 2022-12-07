private fun readInt() = readLine()!!.toInt()
private fun readStrings() = readLine()!!.split(" ")
private fun readInts() = readStrings().map{it.toInt()}
private fun readLongs() = readStrings().map{it.toLong()}

fun main() {
    val T = readInt()
    repeat(T) {
        val S = readLine()!!
        val T = readLine()!!
        val len = S.length
        var p = 0
        var ok = 1
        for (chr in T) {
            if (p >= len) {
                ok = 0
                break
            }
            if (chr == S[p]) {
                p += 1;
            } else {
                if (p + 1 < len && chr == '+' && S[p] == '-' && S[p + 1] == '-') {
                    p += 2;
                } else {
                    ok = 0
                    break
                }
            }
        }
        if (p < len) ok = 0
        if (ok == 1) println("YES")
        else println("NO")
    }
}