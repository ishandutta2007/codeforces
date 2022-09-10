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
        var x = n / (1 + k + k * k + k * k * k)
        print(x)
        print(' ')
        print(x * k)
        print(' ')
        print(x * k * k)
        print(' ')
        print(x * k * k * k)
        print(' ')
        println(' ')
    
    }
}