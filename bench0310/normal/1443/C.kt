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
        var a=mutableListOf(0L)+readLongs()
        var b=mutableListOf(0L)+readLongs()
        var l=0
        var r=(1 shl 30)
        while(l<r-1)
        {
            var m=(l+r)/2
            var sum=0L
            for(i in 1..n) if(a[i]>m) sum+=b[i]
            if(sum<=m) r=m
            else l=m
        }
        print("${r}\n")
    }
}