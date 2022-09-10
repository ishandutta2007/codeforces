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
    while(tc-- > 0){
        var n = readInt()
        var a = IntArray(10)
        var ptr = 0
        var t = n
        while(t > 0){
            var d = t % 10
            a[ptr++] = d
            t /= 10
        }

        var ans = 0
        for(i in 0..ptr- 1){
            if (a[i] > 0){
                ans++
            }
        }

        println(ans)
        for(i in 0..ptr - 1){
            if (a[i] != 0){
                var hto = a[i]
                for(j in 0..i-1){
                    hto = hto * 10;
                }
                print(hto)
                print(' ')  
            }
        }

        println("")
    }
}