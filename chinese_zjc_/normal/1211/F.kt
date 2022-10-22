import java.util.Scanner
val read=Scanner(System.`in`)
val n=read.nextInt()
var pre=IntArray(n)
var suf=IntArray(n)
var nxt=IntArray(n)
var head=IntArray(6,{_->-1})
var ans=IntArray(n)
var cnt=0
fun dfs(now:Int)
{
    while(head[now]!=-1)
    {
        val s=head[now]
        head[now]=nxt[s]
        dfs(pre[s])
        ans[cnt++]=s+1
    }
}
fun main()
{
    read.nextLine()
    for(i in 0 until n)
    {
        val s=read.nextLine()
        pre[i]=when(s.first())
        {
            'k'->0
            'o'->1
            't'->2
            'l'->3
            'i'->4
            'n'->5
            else->-1
        }
        suf[i]=when(s.last())
        {
            'k'->1
            'o'->2
            't'->3
            'l'->4
            'i'->5
            'n'->0
            else->-1
        }
        nxt[i]=head[suf[i]]
        head[suf[i]]=i
    }
    dfs(0)
    print(ans.joinToString(" "))
}