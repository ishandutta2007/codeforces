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
    var a=readInts()
    var c=MutableList(200001,{0})
    var v=MutableList(2,{mutableListOf<Int>()})
    for(x in a)
    {
        if(c[x]==2)
        {
            print("NO\n")
            exitProcess(0)
        }
        v[c[x]++].add(x)
    }
    var OUTPUT=StringBuilder()
    fun pr(s:String){OUTPUT.append(s)}
    pr("YES\n")
    v[0].sort()
    v[1].sortDescending()
    for(j in 0..1)
    {
        pr("${v[j].size}\n")
        for(x in v[j]) pr("$x ")
        pr("\n")
    }
    print(OUTPUT.toString())
}