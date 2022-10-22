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
    val te = readInt()
    repeat(te) {
        val s = readLn().toMutableList()
        val t = readLn().toMutableList()
        if (s.size < t.size) {
            addOL("NO")
        }
        else {
            var failed = false
            var i1 = s.size
            var i2 = t.size
            while (minOf(i1, i2) > 0 && !failed){
                if (t[i2-1] == '-'){
                    i2--
                    if (s[i1-1] != '-')
                        failed = true
                    else
                        i1--
                }
                else{
                    if (s[i1-1] == '+') {
                        i1--
                        i2--
                    }
                    else{
                        if (i1-2 < 0 || s[i1-2] != '-')
                            failed = true
                        else {
                            i1 -= 2
                            i2--
                        }
                    }
                }
            }
            if (failed || maxOf(i1, i2) != 0)
                addOL("NO")
            else {
                addOL("YES")
            }
        }
    }
    outputRes()
}