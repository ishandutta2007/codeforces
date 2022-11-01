import java.math.BigInteger
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
    var s=readLn()
    var t=readLn()
    var a=mutableListOf<Int>()
    var carry=0
    for(i in n-1 downTo 0)
    {
        var now=(s[i].toInt()+t[i].toInt()-2*'a'.toInt()+carry)
        a.add(now%26)
        carry=now/26
    }
    if(carry>0) a.add(carry)
    a.reverse()
    var b=mutableListOf<Int>()
    var now=0
    for(x in a)
    {
        now=26*now+x
        b.add(now/2)
        now%=2
    }
    if(b.size==n+1) b.removeAt(0)
    for(i in 0..n-1) print(('a'.toInt()+b[i]).toChar())
    print("\n")
}