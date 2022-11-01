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
    var s=TreeSet<String>()
    for(i in 0..n-1)
    {
        var t=readLn()
        s.add(t)
    }
    var q=readInt()
    while((q--)>0)
    {
        var v=mutableListOf<String>()
        var t=readLn()
        for(i in 0..m)
        {
            var nt=""
            for(j in 0..m) if(j!=i) nt+=t[j]
            v.add(nt)
        }
        v.sort()
        var res=0
        for(i in 0..m)
        {
            if((i==0||v[i]!=v[i-1])&&s.contains(v[i])) res++
        }
        print("$res\n")
    }
}