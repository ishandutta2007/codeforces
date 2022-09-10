private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
//Fast IO: https://github.com/finalchild/kotlin-fast-io/blob/master/src/solution.kt#L97

fun main(){
    var t = readInt()
    while(t-- > 0){
        var (a, b) = readInts()
        var (c, d) = readInts()
        var ok = false
        if (a == c && (b + d == a)){
            ok = true
        }

        if (a == d && (b + c == a)){
            ok = true
        }

        if (b == c && (a + d == b)){
            ok = true
        }

        if (b == d && (a + c == b)){
            ok = true
        }
        if (ok){
            println("YES")
        }else{
            println("NO")
        }
    }
}