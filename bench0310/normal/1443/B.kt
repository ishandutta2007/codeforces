import kotlin.math.min
import kotlin.math.max
import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    var t=readInt()
    while((t--)>0)
    {
        var (a,b)=readInts()
        var s=readLn()
        var n=s.length
        var l=-1
        for(i in n-1 downTo 0) if(s[i]=='1') l=i
        var res=0
        if(l!=-1)
        {
            var r=-1
            for(i in 0..n-1) if(s[i]=='1') r=i
            while(l<=r)
            {
                var cnt=1
                while(l+1<n&&s[l]==s[l+1])
                {
                    l++
                    cnt++
                }
                if(s[l]=='1') res+=a
                else res+=min(0,cnt*b-a)
                l++
            }
        }
        print("${res}\n")
    }
}