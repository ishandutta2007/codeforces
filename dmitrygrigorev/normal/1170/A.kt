import java.util.*
import kotlin.system.exitProcess
import kotlin.math.*

val reader = Scanner(System.`in`)


fun main(){
    var t = reader.nextInt()
    for (i in 0 until t){
        var a = reader.nextInt()
        var b = reader.nextInt()
        if (a > b){
            var c = a
            a = b
            b = c
        }
        print(1)
        print(" ")
        print(a-1)
        print(" ")
        print(b-a+1)
        print(" ")
    }
}