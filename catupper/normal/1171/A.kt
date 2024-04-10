private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()

fun main(){
    var n = readInt()
    for(i in 1..n){
        var x = readInt()
        if(x <= 7)println(1)
        else if(x % 2 == 0)println(x / 2)
        else println((x-1) / 2)
    }
}