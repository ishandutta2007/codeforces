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
        var (n,x,y)=readInts()
        var res=n
        if(x>y) x=y.also{y=x}
        fun solve(l:Int,r:Int,a:Int):Int=(min(a-l,r-a)+r-l)
        for(i in x+1..y) res=min(res,max(solve(1,i-1,x),solve(i,n,y)))
        print("${res}\n")
    }
}