import java.io.File

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(){
    var t = readInt()
    while(t-- > 0){
       val s = readLn()
       var (a, b, c) = listOf(0, 0, 0)
        for (i in s){
            if (i == '=') a += 1
            if (i == '<') b += 1
            if (i == '>') c += 1
        }

        var ans = '?'
        if (b == 0 && c == 0) ans = '='
        else if (c == 0) ans = '<'
        else if (b == 0) ans = '>'
        println(ans)
    }
}