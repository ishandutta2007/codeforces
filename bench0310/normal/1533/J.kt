import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ").toMutableList()
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    val N=500000
    var v=MutableList(N+2,{mutableListOf<Int>()})
    var n=readInt()
    for(i in 1..n)
    {
        var (y,x)=readInts()
        v[x].add(y)
    }
    for(i in 1..N) v[i].sortDescending()
    var l=MutableList(N+2,{mutableListOf<Int>()})
    var r=MutableList(N+2,{mutableListOf<Int>()})
    var dp=MutableList(N+2,{mutableListOf<Int>()})
    for(i in 1..N)
    {
        var x=0
        var y=0
        var sz=v[i].size
        l[i]=MutableList(sz+1,{0})
        r[i]=MutableList(sz+1,{0})
        for(j in 1..sz)
        {
            while(x+1<=v[i-1].size&&v[i-1][x+1-1]>v[i][j-1]) x++
            while(y+1<=v[i+1].size&&v[i+1][y+1-1]>v[i][j-1]) y++
            l[i][j]=x
            r[i][j]=y
        }
    }
    for(i in 0..N+1) dp[i]=MutableList(v[i].size+1,{0})
    var res=0
    fun go(i:Int)
    {
        var sz=v[i].size
        var ndp=MutableList(sz+1,{0})
        for(j in sz downTo 0) ndp[j]=maxOf(dp[i][j]+sz-j,(if(j<sz) ndp[j+1] else 0))
        var t=0
        for(j in 0..sz)
        {
            t=maxOf(t,dp[i][j])
            ndp[j]=maxOf(ndp[j],t+sz-j)
        }
        dp[i]=ndp
    }
    for(tl in 0..1)
    {
        var tr=tl+N
        go(tl)
        for(i in tl+1..tr-1 step 2)
        {
            for(j in 0..v[i].size) dp[i+1][r[i][j]]=maxOf(dp[i+1][r[i][j]],dp[i-1][l[i][j]]+j)
            go(i+1)
        }
        res+=dp[tr][0]
    }
    print("${res-n}\n")
}