private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var (n, m, q) = readInts()
    var board = Array(n, {LongArray(m)})
    for (i in 0 until n){
        var inp = readLongs()
        for (j in 0 until m){
            board[i][j] = inp[j]   
        }
    }
    
    var xVals = Array(n, {i -> 0L})
    var yVals = Array(m, {i -> 0L})
    for (i in 0 until n){
        for (j in 0 until m){
            xVals[i] += board[i][j]
            yVals[j] += board[i][j]
        }
    }
    
    var xCost = Array(n, {i -> 0L})
    var yCost = Array(m, {i -> 0L})
    for (i in 0 until n){
        for (j in 0 until n){
            if (i - j > 0){
                xCost[j] += (i - j) * xVals[i]
            }
            else{
                xCost[j] += (j - i) * xVals[i]
            }
        }
    }
    
    for (i in 0 until m){
        for (j in 0 until m){
            if (i - j > 0){
                yCost[j] += (i - j) * yVals[i]
            }
            else{
                yCost[j] += (j - i) * yVals[i]
            }
        }
    }
    
    print(xCost.min()!! + yCost.min()!!)
    print(" ")
    
    for (query in 0 until q){
        var (x, y, z) = readInts()
        x -= 1
        y -= 1
        
        var diff = z - board[x][y]
        board[x][y] += diff
        
        for (i in 0 until n){
            if (i - x > 0) {
                xCost[i] += (i - x) * diff
            }
            else{
                xCost[i] += (x - i) * diff
            }
        }
        
        for (i in 0 until m){
            if (i - y > 0) {
                yCost[i] += (i - y) * diff
            }
            else{
                yCost[i] += (y - i) * diff
            }
        }
        
        print(xCost.min()!! + yCost.min()!!)
        print(" ")
    }
}