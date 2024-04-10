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
        var (n, m) = readInts()
        var a = mutableListOf<String>()
        for(i in 0..n-1){
            var s = readLn()
            a.add(s)
        }

        fun check(ans: String): Int{
            for(i in 0..n-1){
                var diff = 0
                for(j in 0..m-1){
                    if (ans[j] != a[i][j]){
                       diff++
                    }
                }

                if (diff > 1){
                    return 0
                }
            }

            return 1
        }


        var fnd = 0
        for(i in 0..m-1){
            for(j in 'a'..'z'){
                if (fnd == 1){
                    continue
                }

                var lol = a[0].toCharArray()
                lol[i] = j

                var s = String(lol)
                if (check(s) == 1){
                    fnd = 1
                    println(s)
                }
            }
        }

        if (fnd == 0) {
            println("-1")
        }
    }
}