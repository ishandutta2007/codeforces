import java.util.*
import kotlin.system.exitProcess

val reader = Scanner(System.`in`)
fun main(){
    val a = reader.nextInt()
    val b = reader.nextInt()
    val c = reader.nextInt()
    for (i in 1..1000){
        if ((i > a) || (i+1 > b) || (i+2 > c)){
            print(3*i)
            exitProcess(0)
        }
    }
}