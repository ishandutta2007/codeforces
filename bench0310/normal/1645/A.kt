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
        var n=readInt()
        var a=(mutableListOf(0)+readInts()).toMutableList()
        if(a[1]!=a[2]&&a[1]!=a[3]) print("1\n")
        else for(i in 1..n) if(a[i]!=a[1]) print("$i\n")
    }
}