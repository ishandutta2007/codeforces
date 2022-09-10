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
    var tc = 1
    while(tc-- > 0) {
        var (n, m, k) = readInts()
        
        var ans = IntArray(n+1)
        for(i in 1..n) ans[i] = -1
        ans[k] = 0
        
        
        for(i in 0..m-1){
            var (a, b) = readInts()
            if (ans[a] == -1 && ans[b] == -1) continue
            if (ans[a] == -1 && ans[b] != -1){
                ans[a] = ans[b]
                ans[b]++
                continue
            }
            
            if (ans[b] == -1 && ans[a] != -1){
                ans[b] = ans[a]
                ans[a]++
                continue
            }
            
            var u = Math.min(ans[a], ans[b] + 1)
            var v = Math.min(ans[b], ans[a] + 1)
            
            ans[a] = v
            ans[b] = u
        }
        
        for(i in 1..n){
            print(ans[i])
            print(' ')
        }
        
        println(' ')
    }
}