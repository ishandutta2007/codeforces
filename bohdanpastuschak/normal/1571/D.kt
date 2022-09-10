private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(){
    val (n, m) = readInts()
    var a = Array(n + 1) { IntArray(n + 1) }
    var winner = IntArray(n + 1)
    var loser = IntArray(n + 1)

    val (_l, _r) = readInts()
    for(i in 2..m){
        val (l, r) = readInts()
        a[l][r]++
        winner[l]++
        loser[r]++
    }

    var ans = 0
    for(i in 1..n){
        for(j in 1..n){
            if (i == j) continue
            if (i == _l && j == _r) ans = Math.max(ans, 0)
            else if (i == _l && j != _r) ans = Math.max(ans, a[i][j])
            else if (i != _l && j == _r) ans = Math.max(ans, a[i][j])
            else{
                ans = Math.max(ans, winner[i] + loser[j] - a[i][j])
            }
        }
    }

    println(ans + 1)
}