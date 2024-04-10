import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ").toMutableList()
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    print("? ${MutableList<Int>(100,{it+1}).joinToString(" ")}\n")
    var a=readInt()
    print("? ${MutableList(100,{(it+1) shl 7}).joinToString(" ")}\n")
    var b=readInt()
    var x=a xor b
    print("! ${(x and ((1 shl 7)-1)) xor a}\n")
}