import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ").toMutableList()
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

private val N=10105
private val inf=(1 shl 30)
private var v=MutableList(N,{mutableListOf<Pair<Int,Int>>()})
private var edges=mutableListOf<Pair<Int,Int>>()
private var cap=mutableListOf<Int>()
private var cost=mutableListOf<Int>()
private var d=MutableList(N,{inf})
private var p=MutableList(N,{-1})

private fun add(a:Int,b:Int,c:Int,price:Int)
{
    var e=cap.size
    v[a].add(Pair(b,e))
    v[b].add(Pair(a,e+1))
    edges.add(Pair(a,b))
    edges.add(Pair(b,a))
    cap.add(c)
    cap.add(0)
    cost.add(price)
    cost.add(-price)
}

private fun go(s:Int,t:Int):Boolean
{
    for(i in 0..t)
    {
        d[i]=inf
        p[i]=-1
    }
    var q=PriorityQueue<Pair<Int,Int>>(t+1,Comparator{a,b->a.first-b.first})
    q.add(Pair(0,s))
    d[s]=0
    p[s]=-2
    while(!q.isEmpty())
    {
        var (da,a)=q.poll()
        if(d[a]<da) continue
        for((to,e) in v[a])
        {
            if(cap[e]>0&&d[a]+cost[e]<d[to])
            {
                d[to]=d[a]+cost[e]
                p[to]=e
                q.add(Pair(d[to],to))
            }
        }
    }
    return (d[t]!=inf)
}

private fun mcmf(s:Int,t:Int):Int
{
    var total=0
    var res=0
    while(go(s,t))
    {
        var a=t
        var flow=inf
        while(a!=s)
        {
            flow=minOf(flow,cap[p[a]])
            a=edges[p[a]].first
        }
        total+=flow
        a=t
        res+=(flow*d[t])
        while(a!=s)
        {
            cap[p[a]]-=flow
            cap[p[a] xor 1]+=flow
            a=edges[p[a]].first
        }
    }
    return res
}

fun main()
{
    var (n1,n2,m)=readInts()
    var k=mutableListOf(0)+readInts()
    var g=MutableList(n2+1,{mutableListOf<Int>()})
    for(i in 1..m)
    {
        var (x,y)=readInts()
        g[y].add(x)
    }
    var s=0
    var t=n1+m+1
    for(i in 1..n1) add(s,i,1,0)
    var x=n1+1
    for(i in 1..n2)
    {
        var best=inf
        for(a in g[i])
        {
            add(a,x,1,0)
            best=minOf(best,k[a])
        }
        var d=g[i].size
        for(j in 0..d-2)
        {
            add(x+j,x+j+1,inf,0)
            add(x+j,t,1,0)
        }
        add(x+d-1,t,1,best)
        x+=d
    }
    print("${mcmf(s,t)}\n")
}