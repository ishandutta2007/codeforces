private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
    var tt = readInt()
    for (qq in 0 until tt) {
        var n = readLn()
        var ans=0
        var prec=1
        for(i in 0 until n.length){
            if(n[i]=='w' || prec==0){
                ans+=1;
                prec=1
            }else{
                prec=0
            }
        }
        println(ans)
        
    }
}