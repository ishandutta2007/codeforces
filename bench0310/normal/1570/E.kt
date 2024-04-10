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
        var s=readLn()
        var l=s.indexOf('1')
        var r=s.lastIndexOf('1')
        var res=0
        if(l!=-1)
        {
            for(i in l..r) if(s[i]=='0') res++
        }
        print("${res}\n")
    }
}