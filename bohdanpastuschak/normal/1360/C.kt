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
    var tc = readInt()
    while(tc-- > 0) {
        var n = readInt()
        var a = readInts()

        var ans = 0
        var odd = 0
        var even = 0
        for(i in 0..n-1){
            if (a[i] % 2 == 0){
                odd++
            }else{
                even++
            }
        }

        var b = a.sorted()
        var fnd = 0
        for(i in 1..n-1){
            if (b[i] == b[i - 1] + 1){
                fnd = 1
            }
        }

        if (even % 2 == 0){
            ans = 1
        }else{
            if (fnd == 1){
                ans = 1
            }
        }

        if (ans == 0){
            println("NO")
        }else{
            println("YES")
        }

    }
}