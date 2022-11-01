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
    var (n,k)=readInts()
    var a=readInts()
    a.add(0)
    a.sort()
    var sum=MutableList(n+1,{0})
    for(i in 1..n) sum[i]=sum[i-1]+a[i]
    fun s(l:Int,r:Int):Int
    {
        return sum[r]-sum[l-1]
    }
    var dp=MutableList(n+1,{MutableList(k+1,{0})})
    for(i in 0..n-1)
    {
        for(j in 0..k)
        {
            dp[i+1][j]=max(dp[i+1][j],dp[i][j])
            for(x in 0..k)
            {
                if(i+2*x>n||j+x>k) break
                dp[i+2*x][j+x]=max(dp[i+2*x][j+x],dp[i][j]+s(i+x+1,i+2*x)-s(i+1,i+x))
            }
        }
    }
    print("${dp[n][k]}\n")
}