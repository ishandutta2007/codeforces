import java.util.*
import kotlin.system.exitProcess

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ").toMutableList()
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    var n=readInt()
    var s=MutableList(2*n-2,{""})
    var v=MutableList(n,{mutableListOf<Int>()})
    for(i in 0..2*n-3)
    {
        s[i]=readLn()
        v[s[i].length].add(i)
    }
    fun go(ta:String,tb:String)
    {
        var t=ta+tb[n-2]
        for(i in 0..n-3) if(ta[i+1]!=tb[i]) return
        var res=MutableList(2*n-2,{'$'})
        for(i in 1..n-1)
        {
            var a=v[i][0]
            var b=v[i][1]
            if(s[a]==t.substring(0,i)&&s[b]==t.substring(n-i,n))
            {
                res[a]='P'
                res[b]='S'
            }
            else if(s[b]==t.substring(0,i)&&s[a]==t.substring(n-i,n))
            {
                res[b]='P'
                res[a]='S'
            }
            else return
        }
        for(c in res) print(c)
        print("\n")
        exitProcess(0)
    }
    go(s[v[n-1][0]],s[v[n-1][1]])
    go(s[v[n-1][1]],s[v[n-1][0]])
}