import kotlin.math.min

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map{it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map{it.toLong()}.toMutableList()

fun main()
{
    var (n,m,d)=readInts()
    var c=readInts()
    var sum=0
    for(a in c) sum+=a
    var now=0
    var res=MutableList<Int>(n+1,{0})
    for(i in 1..m)
    {
        var a=c[i-1]
        var x= min(now+d,n-sum+1)
        for(j in x..x+a-1) res[j]=i
        now=x+a-1
        sum-=a
    }
    if(now+d>=n+1)
    {
        println("YES")
        for(i in 1..n) print("${res[i]} ")
    }
    else println("NO")
}