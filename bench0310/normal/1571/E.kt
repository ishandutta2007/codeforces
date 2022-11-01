import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ").toMutableList()
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    var t=readInt()
    repeat(t)
    {
        var n=readInt()
        var s=readLn()
        var a=readLn()
        var all=(1 shl 4)-1
        val inf=(1 shl 30)
        var now=MutableList(16,{inf})
        var good=MutableList(16,{false})
        good[3]=true
        good[5]=true
        fun cost(b:String,c:Int):Int
        {
            var r=0
            for(i in 0..3)
            {
                if((b[i]=='(')!=(((c shr (3-i)) and 1)==0)) r++
            }
            return r
        }
        for(m in 0..all) if(a[0]=='0'||good[m]) now[m]=cost(s.substring(0,4),m)
        for(i in 4..n-1)
        {
            var nxt=MutableList(16,{inf})
            for(m in 0..all)
            {
                for(x in 0..1)
                {
                    var nm=((2*m) and all)+x
                    var c=0
                    if((s[i]=='(')!=(x==0)) c=1
                    if(a[i-3]=='0'||good[nm]) nxt[nm]=minOf(nxt[nm],now[m]+c)
                }
            }
            now=nxt
        }
        var res=inf
        for(m in 0..all) res=minOf(res,now[m])
        if(res==inf) res=-1
        print("${res}\n")
    }
}