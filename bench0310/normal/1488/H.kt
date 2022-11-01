import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ").toMutableList()
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

private const val mod=998244353
private fun add(a:Int,b:Int):Int=(a+b)%mod
private fun mul(a:Int,b:Int):Int=((a.toLong()*b)%mod).toInt()

private val N=100005
private var tree=MutableList(4*N,{MutableList(16,{0})})
private fun id(a:Int,b:Int):Int=(4*a+b)
private var tp=mutableListOf<Int>()

private fun pull(idx:Int,m:Int)
{
    tree[idx].fill(0)
    for(a in 0..3)
    {
        for(d in 0..3)
        {
            if(tp[m]==1)
            {
                var sum=0
                for(b in 3 downTo 0)
                {
                    if(b+1-tp[m+1]<=3) sum=add(sum,tree[2*idx+1][id(b+1-tp[m+1],d)])
                    tree[idx][id(a,d)]=add(tree[idx][id(a,d)],mul(tree[2*idx][id(a,b)],sum))
                }
            }
            else
            {
                var sum=0
                for(b in 0..3)
                {
                    if(b-tp[m+1]>=0) sum=add(sum,tree[2*idx+1][id(b-tp[m+1],d)])
                    tree[idx][id(a,d)]=add(tree[idx][id(a,d)],mul(tree[2*idx][id(a,b)],sum))
                }
            }
        }
    }
}

private fun build(idx:Int,l:Int,r:Int)
{
    if(l==r) for(i in 0..3) tree[idx][id(i,i)]=1
    else
    {
        var m=(l+r)/2
        build(2*idx,l,m)
        build(2*idx+1,m+1,r)
        pull(idx,m)
    }
}

private fun update(idx:Int,l:Int,r:Int,pos:Int)
{
    if(l<r)
    {
        var m=(l+r)/2
        if(pos<=m) update(2*idx,l,m,pos)
        else update(2*idx+1,m+1,r,pos)
        pull(idx,m)
    }
}

fun main()
{
    var (n,q)=readInts()
    tp=(mutableListOf(0)+readInts()+mutableListOf(0)).toMutableList()
    build(1,1,n)
    var out=StringBuilder()
    while((q--)>0)
    {
        var p=readInt()
        tp[p]=1-tp[p]
        update(1,1,n,p)
        var sum=0
        for(i in 0..15) sum=add(sum,tree[1][i])
        out.append("${sum}\n")
    }
    print(out)
}