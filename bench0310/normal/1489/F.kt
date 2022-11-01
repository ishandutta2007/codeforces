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
    var (n,m,k)=readInts()
    var a=mutableListOf(0)+readInts()
    var sum=MutableList(n+1,{0L})
    for(i in 1..n) sum[i]=sum[i-1]+a[i]
    fun s(l:Int,r:Int):Long{return sum[r]-sum[l-1]}
    var dp=MutableList(n+2,{0})
    var r=n
    var res=0
    for(l in n downTo 1)
    {
        while(s(l,r)>k) r--
        dp[l]=dp[r+1]+1
        if(dp[l]<=m) res=n-l+1
    }
    print("${res}\n")
}