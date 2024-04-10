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
    var a=mutableListOf(0)+readInts()
    var sum=0L
    val lim=1000000
    var one=MutableList(lim+1,{n+1})
    var two=MutableList(lim+1,{0})
    for(i in 1..n)
    {
        sum+=a[i]
        one[a[i]]=minOf(one[a[i]],i)
        two[a[i]]=maxOf(two[a[i]],i)
    }
    var res=mutableListOf<Int>()
    for(i in 1..n)
    {
        var t=sum-a[i]
        if((t%2)==0L&&t/2<=lim&&one[(t/2).toInt()]!=n+1&&(one[(t/2).toInt()]!=i||two[(t/2).toInt()]!=i)) res.add(i)
    }
    print("${res.size}\n")
    for(x in res) print("$x ")
    print("\n")
}