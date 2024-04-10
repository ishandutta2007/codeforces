import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ").toMutableList()
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    var s=readLn()
    var n=s.length
    var v=MutableList(2,{mutableListOf<Int>()})
    var nxt=MutableList(n,{Pair(-1,-1)})
    var pos=MutableList(n,{-1})
    for(i in 0..n-1)
    {
        var t=(s[i]-'0').toInt()
        v[t].add(i)
        pos[i]=v[t].size-1
    }
    var tmp=Pair(n,n)
    for(i in n-1 downTo 0)
    {
        var t=(s[i]-'0').toInt()
        if(t==0) tmp=Pair(i,tmp.second)
        else tmp=Pair(tmp.first,i)
        nxt[i]=tmp
    }
    for(k in 1..n)
    {
        var now=0
        var res=0
        while(true)
        {
            res++
            if(nxt[now].first==n||nxt[now].second==n) break
            var p0=pos[nxt[now].first]
            var p1=pos[nxt[now].second]
            var kth0=p0+k
            var kth1=p1+k
            if(kth0>=v[0].size||kth1>=v[1].size) break
            now=maxOf(v[0][kth0],v[1][kth1])
        }
        print("$res ")
    }
    print("\n")
}