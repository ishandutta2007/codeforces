import kotlin.collections.*
import kotlin.io.*
import kotlin.Array

class Main{
 
    fun solve(inp : InputReader) {
        val T = inp.readlnInt()
        for(test in 1..T){
            var (n,m,a,b) = inp.readlnInts()
            if(a * n != b * m){
                println("NO")
            } else {
                println("YES")
                val shift = (1 until m).lastOrNull { (it * n) % m == 0} ?: 0
                println((0 until n).map {
                    val low = it * shift % m
                    val high = (low + a) % m
                    (0 until m).map {
                        if (low < high) low <= it && it < high
                        else low <= it || it < high
                    } .map{if (it) 1 else 0}
                    .joinToString("")
                }.joinToString("\n"))
            }
        }
    }
 
    class InputReader{
        public fun readln() = readLine()!!
        public fun readlnInt() = readln().toInt()
        public fun readlnLong() = readln().toLong()
        public fun readlnDouble() = readln().toDouble()
 
        public fun readlnStrings() = readln().split(" ")
        public fun readlnInts() = readlnStrings().map{it.toInt()}
        public fun readlnLongs() = readlnStrings().map{it.toLong()}
        public fun readlnDoubles() = readlnStrings().map{it.toDouble()}
    }
}
 
fun main(args : Array <String>){
    Main().solve(Main.InputReader())
}