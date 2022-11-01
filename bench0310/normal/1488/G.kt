import kotlin.math.min
import kotlin.math.max
import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ").toMutableList()
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    var n=readInt()
    var s=TreeSet<Pair<Int,Int>>(Comparator<Pair<Int,Int>>(){a,b->
        when
        {
            (a.first!=b.first) -> a.first.compareTo(b.first)
            else -> a.second.compareTo(b.second)
        }
    })
    var now=MutableList(n+1,{0})
    var vis=MutableList(n+1,{false})
    var div=MutableList(n+1,{mutableListOf<Int>()})
    for(i in 1..n)
    {
        for(j in 2*i..n step i)
        {
            now[j]++
            div[j].add(i)
        }
    }
    for(i in 1..n) s.add(Pair(now[i],i))
    var res=0
    for(i in 1..n)
    {
        //print("i=${i}, s=${s}\n")
        var cnt=0
        var x=0
        while(true)
        {
            var (c,t)=s.last()
            s.remove(Pair(c,t))
            if(now[t]==c)
            {
                cnt=c
                x=t
                break
            }
            else s.add(Pair(now[t],t))
        }
        vis[x]=true
        s.remove(Pair(cnt,x))
        res+=cnt
        for(j in 2*x..n step x)
        {
            if(!vis[j]) now[j]--
        }
        for(j in div[x])
        {
            if(!vis[j]) now[j]--
        }
        print("${res} ")
    }
    print("\n")
}