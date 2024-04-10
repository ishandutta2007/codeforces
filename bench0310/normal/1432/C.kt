private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map{it.toInt()}
private fun readLongs()=readStrings().map{it.toLong()}

fun main()
{
    var q=readInt()
    while((q--)>0)
    {
        var n=readInt()
        var a=readInts()
        var s=0
        for(x in a) s+=x
        println((s+n-1)/n)
    }
}