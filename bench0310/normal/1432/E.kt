import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map{it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map{it.toLong()}.toMutableList()

fun main()
{
    var q=readInt()
    while((q--)>0)
    {
        var (n,k)=readLongs()
        var s=readLn()
        var ones=0
        var b=false
        var res=mutableListOf<Char>()
        for(i in 0..n-1)
        {
            var c=s[i.toInt()]
            if(c=='1') ones++
            else
            {
                if(k>=ones)
                {
                    k-=ones
                    res.add('0')
                }
                else
                {
                    for(j in 1..ones-k) res.add('1')
                    res.add('0')
                    for(j in 1..k) res.add('1')
                    for(j in i+1..n-1) res.add(s[j.toInt()])
                    b=true
                    break
                }
            }
        }
        if(b==false) for(i in 1..ones) res.add('1')
        println(res.joinToString(""))
    }
}