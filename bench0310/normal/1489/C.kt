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
    var s=readLn()
    var l=0
    var res=0;
    while(l<n)
    {
        if(s[l]!='x')
        {
            l++
            continue
        }
        var r=l
        while(r+1<n&&s[r+1]=='x') r++
        res+=max(0,r-l+1-2)
        l=r+1
    }
    println(res)
}