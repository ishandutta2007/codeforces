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
        var a=readInts()
        var v=MutableList(n,{Pair(a[it],it+1)})
        v.sortBy{it.first}
        var l=0
        var r=n-1
        var now=0
        for(i in 1..n)
        {
            if(now>=v[l].first)
            {
                print("${v[l].second} ")
                l++
                now=1
            }
            else
            {
                print("${v[r].second} ")
                r--
                now++
            }
        }
        print("\n")
    }
}