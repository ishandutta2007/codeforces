import kotlin.math.min
import kotlin.math.max
import java.util.*
import kotlin.system.measureNanoTime

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    var (n,k,x)=readInts()
    var a=readInts()
    fun solve(lim:Long):Boolean
    {
        var l=0
        var rm=0
        while(l<n)
        {
            var q=PriorityQueue<Int>(reverseOrder<Int>())
            var sum:Long=0
            for(i in 0..x-1)
            {
                if(l+i<n)
                {
                    q.add(a[l+i])
                    sum+=a[l+i]
                }
            }
            l+=x
            while(sum>lim)
            {
                if(rm==k) return false
                sum-=q.poll()
                rm++
                if(l<n)
                {
                    q.add(a[l])
                    sum+=a[l]
                    l++
                }
            }
        }
        return true
    }
    var l:Long=-1
    var r:Long=10000000000L
    while(l<r-1)
    {
        var m=(l+r)/2
        if(solve(m)==true) r=m
        else l=m
    }
    print("$r\n")
}