import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ").toMutableList()
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    var (n,m)=readInts()
    var grid=MutableList(n,{""})
    for(i in 0..n-1) grid[i]=readLn()
    var cnt=MutableList(32,{0L})
    var up=MutableList(n,{MutableList(m,{0})})
    var s=MutableList(m,{Pair(0,0)})
    var idx=-1
    for(mask in 1..31)
    {
        var allowed=MutableList(5,{false})
        for(j in 0..4) if((mask and (1 shl j))!=0) allowed[j]=true
        for(i in 0..n-1) for(j in 0..m-1) up[i][j]=(if(allowed[grid[i][j]-'A']) 1 else 0)
        var now=0L
        for(i in 0..n-1)
        {
            var sum=0L
            for(j in 0..m-1)
            {
                if(i>0&&up[i][j]==1) up[i][j]+=up[i-1][j]
                var h=up[i][j]
                var c=1
                while(idx>=0&&s[idx].first>=h)
                {
                    var (height,count)=s[idx--]
                    sum-=(height*count)
                    c+=count
                }
                sum+=(h*c)
                s[++idx]=(Pair(h,c))
                now+=sum
            }
            idx=-1
        }
        cnt[mask]=now
        var submask=((mask-1) and mask)
        while(submask>0)
        {
            cnt[mask]-=cnt[submask]
            submask=((submask-1) and mask)
        }
    }
    var res=MutableList(6,{0L})
    for(mask in 1..31)
    {
        var popcnt=0
        for(j in 0..4) if((mask and (1 shl j))!=0) popcnt++
        res[popcnt]+=cnt[mask]
    }
    for(i in 1..5) print("${res[i]} ")
    print("\n")
}