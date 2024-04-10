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
        var (n,k)=readInts()
        var a=readInts()
        a.reverse()
        var sum=MutableList(n,{0})
        sum[0]=a[0]
        for(i in 1..n-1) sum[i]=sum[i-1]+a[i]
        var res=0
        for(i in 0..n-1)
        {
            var x=0
            if(i-((i+1)/k)>=0) x=sum[i-((i+1)/k)]
            res=max(res,sum[i]-x)
        }
        print("$res\n")
    }
}