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
    var (n,m)=readInts()
    var a=mutableListOf(0L)+readLongs()
    var edges=mutableListOf<Triple<Long,Int,Int>>()
    var mn=1
    for(i in 2..n) if(a[i]<a[mn]) mn=i
    for(i in 1..n) if(i!=mn) edges.add(Triple(a[mn]+a[i],mn,i))
    for(i in 1..m)
    {
        var (x,y,w)=readLongs()
        edges.add(Triple(w,x.toInt(),y.toInt()))
    }
    edges.sortBy{it.first}
    var p=MutableList(n+1,{it})
    var sz=MutableList(n+1,{1})
    fun find_set(x:Int):Int
    {
        if(p[x]==x) return x
        else
        {
            p[x]=find_set(p[x])
            return p[x]
        }
    }
    fun merge_sets(tx:Int,ty:Int):Boolean
    {
        var x=find_set(tx)
        var y=find_set(ty)
        if(x==y) return false
        if(sz[x]<sz[y]) x=y.also{y=x}
        p[y]=x
        sz[x]+=sz[y]
        return true
    }
    var res=0L
    for((w,x,y) in edges)
    {
        if(merge_sets(x,y)) res+=w
    }
    println(res)
}