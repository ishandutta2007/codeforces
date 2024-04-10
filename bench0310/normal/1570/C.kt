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
    var b=MutableList<Pair<Int,Int>>(n,{Pair(a[it],it+1)})
    b.sortByDescending{it.first}
    var res=0
    for(i in 0..n-1) res+=i*b[i].first+1
    print("${res}\n")
    b.forEach{print("${it.second} ")}
    print("\n")
}