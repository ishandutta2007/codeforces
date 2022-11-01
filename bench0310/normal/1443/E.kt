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
    var (n,q)=readInts()
    val lim=14
    var changing=min(lim,n)
    var fixed=n-changing
    var x=0L
    var now=MutableList(changing,{it+fixed+1})
    fun mv(y:Int)
    {
        x+=y
        var opt=MutableList(changing,{it+fixed+1})
        var f=mutableListOf<Int>()
        var tmp=x
        for(i in 1..changing)
        {
            f.add((tmp%i).toInt())
            tmp/=i
        }
        f.reverse()
        for(i in 0..changing-1)
        {
            now[i]=opt[f[i]]
            opt.removeAt(f[i])
        }
    }
    fun sum(l:Int,r:Int):Long=((l+r).toLong()*(r-l+1)/2)
    fun query(l:Int,r:Int):Long
    {
        var res=0L
        if(l<=fixed) res+=sum(l,min(r,fixed))
        if(r>fixed) res+=now.subList(max(l,fixed+1)-(fixed+1),r-(fixed+1)+1).sum()
        return res
    }
    while((q--)>0)
    {
        var tmp=readInts()
        if(tmp[0]==1) print("${query(tmp[1],tmp[2])}\n")
        else mv(tmp[1])
    }
}