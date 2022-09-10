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
        var (n, k, x, y) = readInts()
        var a = readInts()
        
        var ans = 0L
        for(i in 0..n-1){
            if (a[i] > k) ans += x
        }
        var b = a.sorted().reversed()
        var curr = 0L
        for(i in 0..n-1) curr += b[i]
        var HUJ = 0L
        HUJ += n
        var X = 0L
        X += x
        var Y = 0L
        Y += y
        if (curr <= HUJ * k){
            if (ans > y) ans = Y
        }
        
        for(i in 0..n-1){
            curr -= b[i]
            if (curr <= HUJ * k){
                var cand = 0L
                cand += y
                cand += (i + 1) * X
                if (ans > cand) ans = cand
            }
        }
        println(ans)
    }
}