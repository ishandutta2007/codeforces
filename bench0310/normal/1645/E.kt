import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ").toMutableList()
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    var (n,k)=readInts()
    var res=mutableListOf<Int>()
    for(i in 0..29) if((n and (1 shl i))>0) res.add(1 shl i)
    if(res.size<=k&&k<=n)
    {
        print("YES\n")
        var tmp=k-res.size
        for(i in 1..tmp)
        {
            var t=res.last()/2
            res.removeLast()
            if(t==1) print("1 1 ")
            else
            {
                res.add(t)
                res.add(t)
            }
        }
        for(x in res) print("$x ")
        print("\n")
    }
    else print("NO\n")
}