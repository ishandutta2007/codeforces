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
        var a = IntArray(n + 1)
        for(i in 1..n) a[i] = 0
        var x = IntArray(m)
        var y = IntArray(m)
        var z = IntArray(m)
        for(i in 0..m-1){
            var (u, v, w) = readInts()
            if (a[u] < w) a[u] = w
            if (a[v] < w) a[v] = w
            x[i] = u
            y[i] = v
            z[i] = w
        }
        
        var ans = 1
        for(i in 0..m-1){
            if (Math.min(a[x[i]], a[y[i]]) != z[i]){
                ans = 0
            }
        }
        if (ans == 0){
            println("NO")
            continue
        }
        
        println("YES")
        for(i in 1..n){
            print(a[i])
            print(' ')
        }
        
        println(' ')
    }
}