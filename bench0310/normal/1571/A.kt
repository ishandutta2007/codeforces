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
    repeat(t)
    {
        var s=readLn()
        var l=false
        var r=false
        for(c in s)
        {
            if(c=='<') l=true
            if(c=='>') r=true
        }
        if(!l&&!r) print("=\n")
        else if(l&&r) print("?\n")
        else if(l) print("<\n")
        else print(">\n")
    }
}