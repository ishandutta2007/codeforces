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
        var n=readInt()
        var (a,va)=readInts()
        var (c,vc)=readInts()
        var b=readInt()
        print("${minOf(va+b-a,vc)}\n")
    }
}