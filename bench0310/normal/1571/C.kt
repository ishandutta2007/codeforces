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
        val lim=200000
        var l=0
        var r=lim
        repeat(n)
        {
            var (a,b,tmp)=readStrings()
            var c=tmp.toInt()
            var m=minOf(a.length,b.length)
            var x=0
            while(x<m&&a[a.length-1-x]==b[b.length-1-x]) x++
            if(c==1)
            {
                l=maxOf(l,0)
                r=minOf(r,x)
            }
            else
            {
                l=maxOf(l,x+1)
                r=minOf(r,lim)
            }
        }
        l=minOf(l,r+1)
        print("${r-l+1}\n")
        if(l<=r) print("${MutableList(r-l+1,{l+it}).joinToString(" ")}\n")
    }
}