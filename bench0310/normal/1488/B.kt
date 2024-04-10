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
        var (n,k)=readInts()
        var s="0"+readLn()
        var cnt=0
        var now=0
        for(i in 1..n)
        {
            if(s[i]=='(') now++
            else now--
            if(now==0) cnt++
        }
        print("${min(n/2,cnt+k)}\n")
    }
}