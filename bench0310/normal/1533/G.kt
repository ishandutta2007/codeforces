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
    while((t--)>0)
    {
        var (n,m)=readInts()
        var a=MutableList(n,{mutableListOf<Int>()})
        for(i in 0..n-1) a[i]=readInts()
        var ord=mutableListOf<Int>()
        var src=Pair(-1,-1)
        var biomes=0
        for(i in 0..n-1)
        {
            for(j in 0..m-1)
            {
                if(a[i][j]!=0&&src.first==-1) src=Pair(i,j)
                if(a[i][j]!=0) biomes++
            }
        }
        var vis=MutableList(n,{MutableList(m,{false})})
        var z=mutableListOf(Pair(1,0),Pair(-1,0),Pair(0,-1),Pair(0,1))
        fun in_grid(r:Int,c:Int):Boolean=(0<=r&&r<n&&0<=c&&c<m)
        fun dfs(r:Int,c:Int)
        {
            vis[r][c]=true
            ord.add(a[r][c])
            for((dr,dc) in z)
            {
                var nr=r+dr
                var nc=c+dc
                if(in_grid(nr,nc)&&a[nr][nc]!=0&&!vis[nr][nc])
                {
                    dfs(nr,nc)
                    ord.add(a[r][c])
                }
            }
        }
        dfs(src.first,src.second)
//        println("biomes: $biomes")
//        println(ord)
        if(ord.size==2*biomes-1)
        {
            print("$biomes $biomes\n")
            var res=MutableList(biomes,{MutableList(biomes,{0})})
            var one=Pair(0,0)
            for(x in ord)
            {
//                println("do $x with one=$one")
                var r=one.first
                var c=one.second
                while(r>=0&&c<biomes)
                {
                    res[r][c]=x
                    r--
                    c++
                }
                if(one.first<biomes-1) one=Pair(one.first+1,one.second)
                else one=Pair(one.first,one.second+1)
            }
            for(i in 0..biomes-1)
            {
                for(j in 0..biomes-1)
                {
                    print("${res[i][j]} ")
                }
                print("\n")
            }
        }
        else print("-1\n")
    }
}