import java.util.*
import kotlin.system.exitProcess

val reader = Scanner(System.`in`)


fun main(){
    var n = reader.nextInt()
    var st = reader.next()
    var arr = Array<Int>(26) {i -> 0}
    if (n==1){
        println("Yes")
        exitProcess(0)
    }
    for (i in 0 until n){
        var ch = st[i]
        arr[ch.toInt() - 'a'.toInt()]++
    }
    var k = false
    for (element in arr){
        if (element > 1){
            k = true
        }
    }
    if (k){
        println("Yes")
    }
    else{
        println("No")
    }

}