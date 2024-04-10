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
        var s=readLn()
        var n=s.length
        var res=0
        var l=0
        while(l<n)
        {
            if(s[l]=='w')
            {
                res++
                l++
            }
            else
            {
                var c=0
                while(l<n&&s[l]=='v')
                {
                    c++
                    l++
                }
                res+=(c/2)
            }
        }
        print("$res\n")
    }
}