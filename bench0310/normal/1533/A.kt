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
        var (n,k)=readInts()
        var res=0
        for(i in 1..n)
        {
            var(l,r)=readInts()
            if(l<=k&&k<=r) res=maxOf(res,r-k+1)
        }
        print("$res\n")
    }
}