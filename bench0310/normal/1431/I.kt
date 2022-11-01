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
    var (n,m,q)=readInts()
    var queries=MutableList(m,{mutableListOf<Int>()})
    var res=MutableList(q,{0})
    var trie=MutableList(n*m+1,{MutableList<Int>(26,{0})})
    fun ctoi(c:Char):Int=(c.toInt()-'a'.toInt())
    var tidx=1
    fun add(a:String):Unit
    {
        var idx=0
        for(c in a)
        {
            if(trie[idx][ctoi(c)]==0) trie[idx][ctoi(c)]=tidx++
            idx=trie[idx][ctoi(c)]
        }
    }
    for(i in 0..n-1) add(readLn().reversed())
    var str=MutableList(q,{""})
    for(i in 0..q-1)
    {
        str[i]=readLn()
        queries[m-1].add(i)
    }
    fun mv(id:Int,pos:Int):Int
    {
        var idx=0
        for(i in pos downTo 0)
        {
            if(trie[idx][ctoi(str[id][i])]==0) return i
            idx=trie[idx][ctoi(str[id][i])]
        }
        return -1
    }
    fun merge(one:Int,two:Int):Unit
    {
        for(i in 0..25)
        {
            if(trie[two][i]==0) continue
            if(trie[one][i]==0) trie[one][i]=trie[two][i]
            else merge(trie[one][i],trie[two][i])
        }
    }
    var active=mutableListOf<Int>()
    for(i in 0..25) if(trie[0][i]!=0) active.add(i)
    for(i in m-1 downTo 0)
    {
        for(id in queries[i])
        {
            var newpos=mv(id,i)
            if(newpos==i) res[id]=-1
            else if(newpos>=0)
            {
                queries[newpos].add(id)
                res[id]++
            }
        }
        var v=MutableList(26,{mutableListOf<Int>()})
        for(i in active) for(j in 0..25) if(trie[0][i]!=0&&trie[trie[0][i]][j]!=0) v[j].add(trie[trie[0][i]][j])
        active.clear()
        for(i in 0..25)
        {
            trie[0][i]=0
            if(v[i].isEmpty()) continue
            for(j in 1..v[i].size-1) merge(v[i][0],v[i][j])
            trie[0][i]=v[i][0]
            active.add(i)
        }
    }
    for(i in 0..q-1) print("${res[i]}\n")
}