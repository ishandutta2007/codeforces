private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
fun main() {
    val t = readInt()
    for (x in 0 until t) {
        var z=readInts()
        var N:Long=z[0].toLong()
        var k:Long=z[1].toLong()
        var x:Long=z[2].toLong()
        var y:Long=z[3].toLong()
        var p=IntArray(N.toInt())
        var q=readInts()
        var tot:Long=0;
        for(i in 0 until N.toInt()){
            tot+=q[i].toLong()
            p[i]=q[i]
        }
        p.sort()
        p.reverse()
        var sol:Long=0
        var sol1:Long=2000000000
        if(tot<=N*k)sol1=y
        for(i in 0 until N.toInt()){
            if(p[i]>k){
                sol+=x
                tot-=p[i]
            }
            if(tot<=N*k){
                if(sol1>sol+y)sol1=sol+y
            }else{
                if(sol1>sol+y+(tot-N*k)*x)sol1=sol+y+(tot-N*k)*x
            }
        }
        var ans:Long=0
        if(sol1<sol)ans=sol1
        else ans=sol
        println(ans)
    }
}