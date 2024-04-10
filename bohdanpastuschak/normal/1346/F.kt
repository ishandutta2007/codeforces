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
    var (n, m, q) = readInts()
    var a = Array(n) {IntArray(m) {0}}
    for(i in 0..n-1){
        var b = readInts()
        for(j in 0..m-1) a[i][j] = b[j]
    }
    
    var row = LongArray(n)
    for(i in 0..n-1) row[i] = 0
    var col = LongArray(m)
    for(i in 0..m-1) col[i] = 0
    
    var sumRow = LongArray(n)
    for(i in 0..n-1){
        var curr = 0L
        for(j in 0..m-1) curr += a[i][j]
        sumRow[i] = curr
    }
    
    var sumCol = LongArray(m)
    for(i in 0..m-1){
        var curr = 0L
        for(j in 0..n-1) curr += a[j][i]
        sumCol[i] = curr
    }
    
    
    for(i in 0..n-1){
        var curr = 0L
        for(j in 0..i-1) curr += sumRow[j] * (i - j)
        for(j in i..n-1) curr += sumRow[j] * (j - i)
        row[i] = curr
    }
    
    
    for(i in 0..m-1){
        var curr = 0L
        for(j in 0..i-1) curr += sumCol[j] * (i - j)
        for(j in i..m-1) curr += sumCol[j] * (j - i)
        col[i] = curr
    }
    
    var best_row = row[0]
    for(i in 1..n-1) if (best_row > row[i]) best_row = row[i]
    var best_col = col[0]
    for(i in 1..m-1) if (best_col > col[i]) best_col = col[i]
    
    print(best_row + best_col)
    print(' ')
    for(iter in 1..q){
        
        var (x, y, z) = readInts()
        --x
        --y
        
        var delta = 0L
        delta += z - a[x][y]
        a[x][y] = z
        
        for(i in 0..n-1){
            if (i < x) row[i] += delta * (x - i)
            else row[i] += delta * (i - x)
        }
        
        
        for(i in 0..m-1){
            if (i < y) col[i] += delta * (y - i)
            else col[i] += delta * (i - y)
        }
        
        
        best_row = row[0]
        for(i in 1..n-1) if (best_row > row[i]) best_row = row[i]
        best_col = col[0]
        for(i in 1..m-1) if (best_col > col[i]) best_col = col[i]
        
        print(best_row + best_col)
        print(' ')
    }
    
    println(' ')
}