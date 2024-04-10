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
    var t=readInt();
    while((t--)>0)
    {
        var (n,a,b)=readLongs()
        var res:Long=(n/2)*min(2*a,b)
        if((n and 1L)==1L) res+=a
        println(res)
    }
}