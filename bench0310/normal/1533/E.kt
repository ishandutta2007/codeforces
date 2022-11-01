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
    var a=(mutableListOf(0)+readInts()).toMutableList()
    var b=(mutableListOf(0)+readInts()).toMutableList()
    a.sort()
    b.sort()
    val inf=(1 shl 30)
    var pre=MutableList(n+1,{-inf}) //max if 1..i are matched to 1..i
    var suf=MutableList(n+2,{-inf}) //max if i..n are matched to i+1..n+1
    for(i in 1..n) pre[i]=maxOf(pre[i-1],b[i]-a[i])
    for(i in n downTo 1) suf[i]=maxOf(suf[i+1],b[i+1]-a[i])
    var q=readInt()
    var c=readInts()
    for(x in c)
    {
        var l=0
        var r=n+1
        while(l<r-1)
        {
            var m=(l+r)/2
            if(a[m]<=x) l=m
            else r=m
        }
        var res=maxOf(pre[l],b[l+1]-x,suf[l+1])
        print("$res ")
    }
    print("\n")
}