import kotlin.math.min
import kotlin.math.max
import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    var (n,m,k)=readInts()
    var t=mutableListOf<Pair<Long,Long>>() //req,c
    var a=mutableListOf<Long>(0)+readLongs()
    var b=mutableListOf<Long>(0)+readLongs()
    for(i in 1..n)
    {
        var c=mutableListOf<Long>(0)+readLongs()
        for(j in 1..m) t.add(Pair(max(a[i],b[j]),c[j]))
    }
    t.sortBy{it.first}
    var l=0
    var v=mutableListOf<Pair<Long,Long>>()
    while(l<n*m)
    {
        var r=l
        while(r+1<n*m&&t[r+1].first==t[l].first) r++
        var mx=0L
        for(i in l..r) mx=max(mx,t[i].second)
        v.add(Pair(t[l].first,mx))
        l=r+1
    }
    var res:Long=(1L shl 60)
    var sz=v.size
    fun solve():Unit
    {
        var mv:Long=0
        var idx=0
        var score:Long=0
        var mx:Long=0
        while(idx<sz)
        {
            while(idx<sz&&score>=v[idx].first)
            {
                mx=max(mx,v[idx].second)
                idx++
            }
            if(idx==sz) break
            var x:Long=(v[idx].first-score+mx-1)/mx
            score+=(x*mx)
            mv+=x
        }
        res=min(res,mv)
    }
    for(i in 0..sz-1)
    {
        v[i]=Pair(v[i].first,v[i].second+k)
        solve()
        v[i]=Pair(v[i].first,v[i].second-k)
    }
    print("$res\n")
}