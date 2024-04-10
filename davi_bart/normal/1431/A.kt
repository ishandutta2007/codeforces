private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
    var tt = readInt()
    for (qq in 0 until tt) {
        var n = readInt()
        var k=readLongs()
        val v: Array<Long> = k.toTypedArray()
        v.sort()
        var ma=0.toLong()
        for(i in 0 until n){
            ma=maxOf(ma,(n-i)*v[i])
        }
        println(ma)
        
    }
}