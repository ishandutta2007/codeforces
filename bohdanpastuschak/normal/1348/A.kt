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
        var n = readInt()
        var ans = 0
        var pw = 2
        for(i in 1..n){
            if (i <= n / 2 - 1 || i == n) {
                ans += pw
            }else{
                ans -= pw
            }
            pw += pw
        }

        println(ans)
    }
}