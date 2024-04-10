import kotlin.math.min
import kotlin.math.max
import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ").toMutableList()
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

private val N=200005
private var tree=MutableList(4*N,{0L})
private var lazy=MutableList(4*N,{0})

private fun push(idx:Int,l:Int,r:Int,m:Int)
{
    tree[2*idx]=lazy[idx].toLong()*(m-l+1)
    lazy[2*idx]=lazy[idx]
    tree[2*idx+1]=lazy[idx].toLong()*(r-m)
    lazy[2*idx+1]=lazy[idx]
    lazy[idx]=0
}

private fun update(idx:Int,l:Int,r:Int,ql:Int,qr:Int,x:Int)
{
    if(ql>qr) return
    if(l==ql&&r==qr)
    {
        tree[idx]=x.toLong()*(r-l+1)
        lazy[idx]=x
    }
    else
    {
        var m=(l+r)/2
        if(lazy[idx]>0) push(idx,l,r,m)
        update(2*idx,l,m,ql,min(qr,m),x)
        update(2*idx+1,m+1,r,max(ql,m+1),qr,x)
        tree[idx]=tree[2*idx]+tree[2*idx+1]
    }
}

private fun query(idx:Int,l:Int,r:Int,ql:Int,qr:Int):Long
{
    if(ql>qr) return 0L
    if(l==ql&&r==qr) return tree[idx]
    var m=(l+r)/2
    if(lazy[idx]>0) push(idx,l,r,m)
    return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr)
}

fun main()
{
    var n=readInt()
    var c=mutableListOf(0)+readInts()
    var q=readInt()
    var queries=mutableListOf<Triple<Int,Int,Int>>()
    for(i in 1..q)
    {
        var (l,r)=readInts()
        queries.add(Triple(l,r,i))
    }
    queries.sortBy{it.second}
    var s=Stack<Pair<Int,Int>>()
    s.push(Pair(1 shl 30,0))
    var res=MutableList(q+1,{0L})
    var idx=0
    for(i in 1..n)
    {
        while(s.peek().first<=c[i]) s.pop()
        update(1,1,n,s.peek().second+1,i,c[i])
        s.push(Pair(c[i],i))
        while(idx<q&&queries[idx].second==i)
        {
            res[queries[idx].third]=query(1,1,n,queries[idx].first,i)
            idx++
        }
    }
    for(i in 1..q) print("${res[i]} ")
    print("\n")
}