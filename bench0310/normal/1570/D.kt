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
    var s=TreeSet<Int>()
    while(!s.contains(n))
    {
        s.add(n)
        n++
        while((n%10)==0) n/=10
    }
    print("${s.size}\n")
}