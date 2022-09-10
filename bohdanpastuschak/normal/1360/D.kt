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
        var (n, k) = readInts()
        var ans = n
        var i = 1
        while(i * i <= n){
            if (n % i == 0){
                var j = i
                if (j <= k){
                    ans = Math.min(ans, n / j)
                }

                j = n / i
                if (j <= k){
                    ans = Math.min(ans, n / j)
                }
            }

            i++
        }
        println(ans)
    }
}