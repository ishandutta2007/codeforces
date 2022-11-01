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
        var n=readInt()
        println(n-1-(n+1+1)/2+1)
    }
}