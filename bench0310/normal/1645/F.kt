import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ").toMutableList()
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    var n=readInt()
    var a=readInts()
    a.sort()
    var s=TreeSet<Int>()
    var res=0
    for(x in a)
    {
        for(i in -1..1)
        {
            if(x+i>=1&&!s.contains(x+i))
            {
                s.add(x+i)
                res++
                break
            }
        }
    }
    print("$res\n")
}