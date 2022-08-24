import java.util.*
import kotlin.system.exitProcess

val reader = Scanner(System.`in`)


fun main(){
    var x = reader.nextInt()
    var y = reader.nextInt()
    var z = reader.nextInt()
    var a = reader.nextInt()
    var b = reader.nextInt()
    var c = reader.nextInt()
    if (x+y+z > a+b+c){
        println("NO")
        exitProcess(0)
    }
    if (x > a){
        println("NO")
        exitProcess(0)
    }
    a -= x
    if (y > a + b){
        println("NO")
        exitProcess(0)
    }
    println("YES")
}