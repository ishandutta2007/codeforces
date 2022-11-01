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
    var n=readInt()
    var vis=MutableList<Boolean>(1001,{false})
    var a=readInts()
    var res=mutableListOf<Int>()
    a.reverse()
    for(x in a)
    {
        if(!vis[x])
        {
            res.add(x)
            vis[x]=true
        }
    }
    res.reverse()
    print("${res.size}\n")
    for(x in res) print("${x} ")
    print("\n")
}