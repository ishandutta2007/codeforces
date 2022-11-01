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
        var (x,y)=readLongs()
        var p=1L
        while(x*p*10<=y) p*=10
        var res=0L
        while(y>0)
        {
            while(x*p<=y)
            {
                y-=(x*p)
                res++
            }
            p/=10
            if(p==0L) break
        }
        res+=y
        print("${res}\n")
    }
}