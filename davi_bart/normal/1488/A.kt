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
        var (a,b)=readLongs();
        var x=1000000000.toLong()
        var ans=0.toLong()
        while(x>0){
            var w=x*a
            while(w<=b){
                b-=w
                ans+=1
            }
            x/=10
        }
        ans+=b
        println(ans)
            
        
    }
}