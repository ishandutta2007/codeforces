import java.util.*
import kotlin.system.exitProcess
import kotlin.math.*

val reader = Scanner(System.`in`)


fun main(){
    var n = reader.nextInt()
    for (i in 0 until n){
        var s = reader.next()
        var t = reader.next()
        var cur = 0
        var can = true
        for (j in 0 until t.length){
            if (cur >= s.length){
                can = false
                break
            }
            if (t[j] == '-'){
                if (s[cur] == '+'){
                    can = false
                    break
                }
                cur++
                continue
            }
            if (s[cur] == '+'){
                cur++
                continue
            }
            if (cur + 1 >= s.length){
                can = false
                break
            }
            if (s[cur+1] != '-'){
                can = false;
                break
            }
            cur += 2
        }
        if (cur != s.length){
            can = false
        }
        if (can) println("YES")
        else println("NO")
    }
}