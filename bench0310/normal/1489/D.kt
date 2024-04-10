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
    var s=MutableList<String>(n,{""})
    for(i in 0..n-1) s[i]=readLn()
    s.sortBy{it.length}
    fun is_substr(a:String,b:String):Boolean
    {
        var n=a.length
        var m=b.length
        for(i in 0..n-m) if(a.substring(i,i+m)==b) return true
        return false
    }
    var ok=true
    for(i in 0..n-2) if(!is_substr(s[i+1],s[i])) ok=false
    if(ok)
    {
        println("YES")
        for(a in s) println(a)
    }
    else println("NO")
}