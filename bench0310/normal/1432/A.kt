private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map{it.toInt()}

fun main()
{
    var t=readInt()
    while((t--)>0)
    {
        var (a,b)=readInts()
        println(a+b)
    }
}