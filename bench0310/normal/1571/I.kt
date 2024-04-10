import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ").toMutableList()
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    var t=readInt()
    while((t--)>0)
    {
        var n=readInt()
        var tl=readInts()
        var tr=readInts()
        var v=MutableList(n,{Triple(tl[it],tr[it],it+1)})
        v.sortBy{it.first}
        var l=0
        var r=(1 shl 30)
        var x=0
        var p=MutableList<Int>(n,{-1})
        fun go(y:Int):Int
        {
            x=y
            var idx=0
            var q=PriorityQueue<Pair<Int,Int>>(n,Comparator{a,b->
                when
                {
                    (a.first!=b.first)->a.first.compareTo(b.first)
                    else->a.second.compareTo(b.second)
                }
            })
            for(i in 0..n-1)
            {
                var pos=x+i
                while(idx<n&&v[idx].first<=pos)
                {
                    q.add(Pair(v[idx].second,v[idx].third))
                    idx++
                }
                if(q.isEmpty()) return -1
                var (tx,id)=q.poll()
                if(tx<pos) return 1
                p[i]=id
            }
            return 0
        }
        while(l<r-1)
        {
            var m=(l+r)/2
            if(go(m)<=0) l=m
            else r=m
        }
        if(go(l)==0)
        {
            print("${x}\n")
            for(i in 0..n-1) print("${p[i]} ")
            print("\n")
        }
        else print("-1\n")
    }
}