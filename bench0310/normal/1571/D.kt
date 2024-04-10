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
    var c=MutableList(n+1,{MutableList(n+1,{0})})
    var one=MutableList(n+1,{0})
    var two=MutableList(n+1,{0})
    var a=MutableList(m+1,{0})
    var b=MutableList(m+1,{0})
    for(i in 1..m)
    {
        var (x,y)=readInts()
        c[x][y]++
        one[x]++
        two[y]++
        a[i]=x
        b[i]=y
    }
    var res=1
    for(x in 1..n)
    {
        for(y in 1..n)
        {
            if(x==y) continue
            var c2=c[x][y]
            var c1=one[x]+two[y]-2*c[x][y]
            if(a[1]==x&&b[1]==y) res=maxOf(res,1)
            else if(a[1]==x||b[1]==y) res=maxOf(res,c2+1)
            else res=maxOf(res,c2+c1+1)
        }
    }
    print("${res}\n")
}