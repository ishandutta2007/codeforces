private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var t = readInt()
    for (i in 0 until t) {
        var (n, k, x, y) = readLongs()
        var a = readLongs()
        
        var opt1 = 0L
        for (v in a){
            if (v > k){
                opt1 += x
            }
        }
        
        var opt2 = y
        var tot = a.sum()
        var sorted = a.sortedDescending();
        var curr = 0
        while (tot > k * n){
            tot -= sorted[curr]
            curr += 1
            opt2 += x
        }
        
        if (opt1 < opt2){
            println(opt1)
        }
        else{
            println(opt2)
        }
    }
}