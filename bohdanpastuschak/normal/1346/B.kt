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
        var (n, k1, k2) = readInts()
        if (k1 + k1 < k2) k2 = k1 + k1
        var ans = 0
        var s = readLn()
        var cnt = 0
        
        fun get(x: Int) : Int{
            if (x % 2 == 0) return x / 2 * k2
            return x / 2 * k2 + k1
        }
        
        for(i in 0..n-1){
            if (s[i] == '0'){
                ans += get(cnt)
                cnt = 0
            }else{
                cnt++
            }
        }
        
        ans += get(cnt)
        
        println(ans)
    }
}