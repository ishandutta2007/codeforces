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
    val N=200000
    var pos=MutableList<Int>(N+1,{0})
    var q=readInt()
    var l=1
    var r=0
    while((q--)>0)
    {
        var (t,tmp)=readStrings()
        var id=tmp.toInt()
        if(t=="L") pos[id]=--l
        if(t=="R") pos[id]=++r
        if(t=="?") print("${min(pos[id]-l,r-pos[id])}\n")
    }
}