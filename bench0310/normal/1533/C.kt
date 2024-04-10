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
        var s=readLn()
        var candies=MutableList(n,{it})
        var cnt=0
        for(i in 0..n-1) if(s[i]=='1') cnt++
        var now=0
        var res=0
        while(cnt>0)
        {
            if(s[candies[now]]=='1') cnt--
            res++
            candies.removeAt(now)
            if(cnt==0) break
            now=now%candies.size
            for(i in 1..k-1)
            {
                now=(now+1)%candies.size
            }
        }
        print("$res\n")
    }
}