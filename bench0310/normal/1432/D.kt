private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map{it.toInt()}
private fun readLongs()=readStrings().map{it.toLong()}

fun main()
{
    var t=readInt()
    while((t--)>0)
    {
        var (n,a,b)=readInts()
        var s=CharArray(n)
        for(i in 0..a-b+1-1) s[i]='a'
        for(i in a-b+1..a-1) s[i]=('a'.toInt()+i-(a-b+1)+1).toChar()
        for(i in a..n-1) s[i]=s[i-a]
        println(s)
    }
}