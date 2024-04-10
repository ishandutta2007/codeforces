import java.util.Scanner
public class node(var sum:Long,var tag:Long)
val read=Scanner(System.`in`)
var n=0
var m=0
var ans=Array<Long>(200005,{i->0})
var a=Array<Long>(200005,{i->0})
var t=Array<node>(524293,{i->node(0,0)})
var top=0
var sta=IntArray(200005)
var lst=IntArray(200005)
var head=IntArray(200005)
var query=IntArray(200005)
fun pushup(now:Int){t[now].sum=t[now+now].sum+t[now+now+1].sum}
fun pushdown(now:Int,l:Int,r:Int)
{
    val mid = (l+r) shr 1
    if(t[now].tag!=t[now].tag shl 1)
    {
        t[now+now].sum=(mid-l+1)*t[now].tag
        t[now+now].tag=t[now].tag
        t[now+now+1].sum=(r-mid)*t[now].tag
        t[now+now+1].tag=t[now].tag
        t[now].tag=0
    }
}
fun modify(L:Int,R:Int,v:Long,now:Int,l:Int,r:Int)
{
    if(r<L||R<l)return
    if(L<=l&&r<=R)
    {
        t[now].sum = v * (r - l + 1)
        t[now].tag = v
        return
    }
    val mid = (l+r) shr 1
    pushdown(now, l, r)
    modify(L, R, v, now+now, l, mid)
    modify(L, R, v, now+now+1, mid+1, r)
    pushup(now)
}
fun Sum(L:Int,R:Int,now:Int,l:Int,r:Int):Long
{
    if (r < L || R < l)
        return 0
    if (L <= l && r <= R)
        return t[now].sum
    pushdown(now, l, r)
    val mid = (l+r) shr 1
    return Sum(L, R, now+now, l, mid) + Sum(L, R, now+now+1, mid+1, r)
}
fun main()
{
    n=read.nextInt()
    for(i in 1..n)
        a[i]=read.nextLong()
    m=read.nextInt()
    for(i in 1..m)
    {
        var l=read.nextInt()
        var r=read.nextInt()
        query[i]=l
        lst[i]=head[r]
        head[r]=i
    }
    for(i in 1..n)
    {
        while(top>0&&a[sta[top]]<a[i])
            --top
        sta[++top]=i
        modify(sta[top-1]+1,i,a[i],1,1,n)
        var j=head[i]
        while(j!=0)
        {
            ans[j]=Sum(query[j],i,1,1,n)
            j=lst[j]
        }
    }
    println(ans.joinToString(" ").drop(2).dropLast((200004-m)*2))
}