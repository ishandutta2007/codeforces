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
        var (n,s)=readLongs()
        fun ok(m:Long):Boolean
        {
            var mn=0L
            var now=m
            for(i in 1L..n)
            {
                if(now==1L)
                {
                    mn+=(n-i+1)
                    break
                }
                mn+=now
                now=(now+1)/2
            }
            return (mn<=s)
        }
        var l=(s+n-1)/n
        var r=s+1
        while(l<r-1)
        {
            var m=(l+r)/2
            if(ok(m)) l=m
            else r=m
        }
        print("${l}\n")
    }
}