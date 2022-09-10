private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
fun main(args: Array<String>) {
    var n = 4
    var a = readInts()
    var id = 0;
    for (i in 1..3) {
    	if (a[i] > a[id]){
    		id = i
    	}
    }
    
    for (i in 0..3) {
    	if (a[i] != a[id]){
    		print("${a[id] - a[i]} ")
    	}
    }
    
}