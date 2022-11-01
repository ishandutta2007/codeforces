import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ").toMutableList()
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    val mod=998244353L
    fun add(a:Long,b:Long):Long=(a+b)%mod
    fun sub(a:Long,b:Long):Long=(a-b+mod)%mod
    fun mul(a:Long,b:Long):Long=(a*b)%mod
    val inv=616898040L
    var (n,a,b)=readInts()
    var xline=MutableList(a+1,{0})
    var yline=MutableList(b+1,{0})
    var one=TreeMap<Int,MutableList<Long>>()
    var two=TreeMap<Int,MutableList<Long>>()
    for(i in 1..n)
    {
        var (x,y,tmp)=readInts()
        var p=mul(tmp.toLong(),inv)
        if(!one.containsKey(x-y)) one.put(x-y,mutableListOf())
        if(!two.containsKey(x+y)) two.put(x+y,mutableListOf())
        one[x-y]!!.add(p)
        two[x+y]!!.add(p)
        xline[x]=1
        yline[y]=1
    }
    var Ev=(2*(a+b)).toLong()
    var Ee=Ev
    fun p_one(s:Int):Long
    {
        var p=1L
        if(one.containsKey(s)) for(q in one[s]!!) p=mul(p,sub(1,q))
        return p
    }
    fun p_two(s:Int):Long
    {
        var p=1L
        if(two.containsKey(s)) for(q in two[s]!!) p=mul(p,sub(1,q))
        return p
    }
    //vertices
    for(x in 1..a)
    {
        for(y in 1..b)
        {
            //grid
            if(x<a&&y<b)
            {
                if(xline[x]==1||yline[y]==1) Ev=add(Ev,1)
                else Ev=add(Ev,sub(1,mul(p_one(x-y),p_two(x+y))))
            }
            //cell
            Ev=add(Ev,sub(1,mul(p_one(x-y),p_two(x+y-1))))
        }
    }
    //edges
    for(x in 1..a-1) if(xline[x]==1) Ee=add(Ee,b.toLong())
    for(y in 1..b-1) if(yline[y]==1) Ee=add(Ee,a.toLong())
    fun ok(x:Int,y:Int):Boolean=(0<=x&&x<=a&&0<=y&&y<=b)
    //one
    var x=0
    var y=b
    while(x<=a)
    {
        var tx=x
        var ty=y
        while(ok(tx+1,ty+1)){tx++; ty++}
        var c=(2*(tx-x)).toLong()
        Ee=add(Ee,mul(c,sub(1,p_one(x-y))))
        if(y>0) y--
        else x++
    }
    //two
    x=a
    y=b
    while(y>=0)
    {
        var tx=x
        var ty=y
        while(ok(tx+1,ty-1)){tx++; ty--}
        var c=(2*(tx-x)).toLong()
        Ee=add(Ee,mul(c,sub(1,p_two(x+y))))
        if(x>0) x--
        else y--
    }
    print("${add(sub(Ee,Ev),1)}\n")
}