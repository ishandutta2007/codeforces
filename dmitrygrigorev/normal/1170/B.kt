import java.util.*
import kotlin.system.exitProcess
import kotlin.math.*

val reader = Scanner(System.`in`)


fun main(){
    var n = reader.nextInt()
    var mx1=0
    var mx2=0
    var ans = 0
    for (i in 0 until n){
        var a = reader.nextInt()
        if (a >= mx1){
            mx2 = mx1
            mx1 = a
        }
        else if (a >= mx2){
            mx2 = a
        }
        if (a < mx2){
            ans++
        }
    }
    print(ans)
}