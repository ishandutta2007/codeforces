private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var (n, m, k) = readInts()
    var best = Array(n, {i -> (m + 1)})
    best[k - 1] = 0
    for (i in 0 until m){
        var (x, y) = readInts()
        x -= 1
        y -= 1
        
        var prevX = best[x]
        var prevY = best[y]
        
        best[x] = prevY
        if (prevX + 1 < best[x]) best[x] = prevX + 1
        
        best[y] = prevX
        if (prevY + 1 < best[y]) best[y] = prevY + 1
    }
    
    for (v in best){
        if (v > m){
            print(-1)
        }
        else{
            print(v)
        }
        print(" ")
    }
}