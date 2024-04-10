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
    var t=readInt()
    while((t--)>0)
    {
        var n=readInt()
        var a=mutableListOf(0)+readInts()
        var pos=MutableList(n+1,{mutableListOf<Int>()})
        for(i in 1..n) pos[a[i]].add(i)
        var tmp=MutableList(n+1,{-1})
        for(i in 1..n)
        {
            if(pos[i].size==2) tmp[pos[i][0]]=pos[i][1]
        }
        var best=MutableList(n+1,{-1})
        best[0]=n+1
        var res=1
        for(i in 1..n)
        {
            if(tmp[i]==-1) continue
            var l=0
            var r=n
            while(l<r-1)
            {
                var m=(l+r)/2
                if(best[m]<tmp[i]) r=m
                else l=m
            }
            best[r]=tmp[i]
            if(i+1==tmp[i]) res=max(res,2*r)
            else res=max(res,2*r+1)
            //print("after processing ${tmp[i]}, r=${r}: $best\n")
        }
        print("${res}\n")
    }
}