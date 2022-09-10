private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
fun main(args: Array<String>) {
    var n = readInt()
    var a = readInts()
    var was = IntArray(1111)
    var ans = IntArray(1111)
    var x = 0
    var i = n - 1;
    
    while(i >= 0)
    {
        if (was[a[i]] == 0)
        {
        was[a[i]] = 1
        ans[x] = a[i]
        x += 1
        
        }
        i -= 1
    }
    
    println(x)
    for(i in x - 1 downTo 0) print("${ans[i]} ")
    
}