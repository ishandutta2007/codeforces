import kotlin.reflect.jvm.internal.impl.protobuf.LazyStringArrayList

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
        var ans = 1

        var a = mutableListOf<String>()
        for(i in 0..n-1){
            var s = readLn()
            a.add(s)
        }

        for(i in 0..n-2){
            for(j in 0..n-2){
                if (a[i][j] == '1' && a[i + 1][j] == '0' && a[i][j + 1] == '0'){
                    ans = 0
                }
            }
        }

        if (ans == 1){
            println("YES")
        }else{
            println("NO")
        }
    }
}