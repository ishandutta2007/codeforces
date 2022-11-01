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
    var a=MutableList(n,{readInts()})
    var res=mutableListOf<Pair<Int,Int>>()
    var b=MutableList(n,{MutableList(m,{0})})
    for(i in 0..n-2)
    {
        for(j in 0..m-2)
        {
            if(minOf(a[i][j],a[i][j+1],a[i+1][j],a[i+1][j+1])==1)
            {
                b[i][j]=1
                b[i][j+1]=1
                b[i+1][j]=1
                b[i+1][j+1]=1
                res.add(Pair(i+1,j+1))
            }
        }
    }
    if(a==b)
    {
        print("${res.size}\n")
        for((i,j) in res) print("${i} ${j}\n")
    }
    else print("-1\n")
}