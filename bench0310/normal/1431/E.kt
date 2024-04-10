import java.lang.Math.abs
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
    var t=readInt()
    while((t--)>0)
    {
        var n=readInt()
        var tmp=readInts()
        var a=MutableList(n,{Pair(tmp[it],it+1)})
        a.sortBy{it.first}
        tmp=readInts()
        var b=MutableList(n,{Pair(tmp[it],it+1)})
        b.sortBy{it.first}
        var res=-1
        var pos=MutableList(n,{0})
        fun ch(x:Int):Unit
        {
            var now=1000000
            for(i in 0..n-1) now=min(now,abs(a[i].first-b[(i+x)%n].first))
            if(now>res)
            {
                res=now
                for(i in 0..n-1) pos[a[i].second-1]=b[(i+x)%n].second
            }
        }
        for(i in 0..n-1) ch(i)
        b.reverse()
        for(i in 0..n-1) ch(i)
        for(i in 0..n-1) print("${pos[i]} ")
        print("\n")
    }
}