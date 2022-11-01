import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ").toMutableList()
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

private val N=300005
private val inf=(1L shl 60)
private var tree=MutableList(4*N,{-inf})

private fun update(idx:Int,l:Int,r:Int,pos:Int,x:Long)
{
    if(l==r) tree[idx]=maxOf(tree[idx],x)
    else
    {
        var m=(l+r)/2
        if(pos<=m) update(2*idx,l,m,pos,x)
        else update(2*idx+1,m+1,r,pos,x)
        tree[idx]=maxOf(tree[2*idx],tree[2*idx+1])
    }
}

private fun query(idx:Int,l:Int,r:Int,ql:Int,qr:Int):Long
{
    if(ql>qr) return -inf
    if(l==ql&&r==qr) return tree[idx]
    var m=(l+r)/2
    return maxOf(query(2*idx,l,m,ql,minOf(qr,m)),query(2*idx+1,m+1,r,maxOf(ql,m+1),qr))
}

fun main()
{
    var (n,m)=readInts()
//    var n=(1..2).random()
//    var m=(1..3).random()
//    println("$n $m")
    var v=mutableListOf<Triple<Int,Int,Int>>()
//    var dp=MutableList(m+1,{-inf})
//    dp[m]=0
    for(i in 1..n)
    {
        var k=readInt()
        var a=readInts()
        var b=readInts()
//        var k=2
//        var a=MutableList(k,{(1..10).random()})
//        var b=MutableList(k,{(0..m).random()})
//        println(k)
//        println(a)
//        println(b)
        for(j in 0..k-1) v.add(Triple(b[j],i,a[j]))
//        var ndp=MutableList(m+1,{dp[it]})
//        for(j in 0..m-1) ndp[j]=maxOf(ndp[j],dp[j+1])
//        for(j in 0..k-1) if(dp[b[j]]!=-inf) ndp[b[j]]=maxOf(ndp[b[j]],dp[b[j]]+a[j])
//        dp=ndp
    }
//    var fin=0L
//    for(i in 0..m) fin=maxOf(fin,dp[i])
//    println(fin)
    v.sortWith(Comparator{a,b->
        when
        {
            (a.first+a.second!=b.first+b.second)->(a.first+a.second-(b.first+b.second))
            (a.second!=b.second)->b.second-a.second
            else->0
        }
    })
    var ini=false
    for((b,i,a) in v)
    {
        if(!ini&&i+b>=m+1)
        {
//            println("Ini")
            update(1,0,m,m,0L)
            ini=true
        }
//        println("Process $b $i $a")
        var now=query(1,0,m,b,m)
        if(now!=-inf) update(1,0,m,b,now+a)
    }
    var res=maxOf(0L,query(1,0,m,0,m))
    print("${res}\n")
}