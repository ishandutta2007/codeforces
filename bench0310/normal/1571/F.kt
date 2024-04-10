import java.util.*
import kotlin.system.exitProcess

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ").toMutableList()
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    var (n,m)=readInts()
    var res=MutableList(n+1,{0})
    var dp=MutableList(m+1,{-1})
    dp[0]=0
    var k=MutableList(n+1,{0})
    var t=MutableList(n+1,{0})
    var e=m
    fun bad()
    {
        print("-1\n")
        exitProcess(0)
    }
    var cnt=0
    for(i in 1..n)
    {
        var (a,b)=readInts()
        k[i]=a
        t[i]=b
        if(b==1)
        {
            if(a>e) bad()
            res[i]=e-a+1
            e-=a
        }
        else
        {
            for(j in m-a downTo 0)
            {
                if(dp[j]!=-1&&dp[j+a]==-1) dp[j+a]=i
            }
            cnt+=a
        }
    }
    var x=(e+1)/2 //odds
    var y=e/2 //evens
    var odd=-1
    for(i in 0..m)
    {
        if(dp[i]!=-1&&i<=x&&cnt-i<=y) odd=i
    }
    if(odd==-1) bad()
    var vis=MutableList(n+1,{false})
    var tmp=odd
    var now=1
    while(tmp>0)
    {
        var id=dp[tmp]
        res[id]=now
        now+=2*k[id]
        tmp-=k[id]
        vis[id]=true
    }
    now=2
    for(i in 1..n)
    {
        if(t[i]==1||vis[i]) continue
        res[i]=now
        now+=2*k[i]
    }
    for(i in 1..n) print("${res[i]} ")
    print("\n")
}