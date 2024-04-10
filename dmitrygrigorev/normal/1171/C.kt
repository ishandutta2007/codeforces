import java.util.*
import kotlin.system.exitProcess

val reader = Scanner(System.`in`)

fun palindrome(m : MutableList<Char>) : Boolean{
    for (i in 0 until m.size){
        if (m[i] != m[m.size - i - 1]){
            return false
        }
    }
    return true
}

fun solve() {
    var t = reader.next()
    val arr = mutableListOf<Char>()
    for (i in 1..t.length){
        arr.add(t[i-1])
    }
    val k = 1000 / t.length
    for (i in 1..k){
        arr.shuffle()
        if (!palindrome(arr)){
            for (item in arr){
                print(item)
            }
            println()
            return
        }
    }
    println(-1)
}

fun main(){
    var n = reader.nextInt()
    for (i in 1..n){
        solve()
    }
}