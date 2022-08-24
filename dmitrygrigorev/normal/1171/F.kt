import java.util.*
import kotlin.system.exitProcess

val reader = Scanner(System.`in`)

class P(val l: Int, val r:Int, val ind:Int){

}

fun solve(){
    var n = reader.nextInt()
    var v = mutableListOf<P>()
    for (i in 0 until n){
        var l = reader.nextInt()
        var r = reader.nextInt()
        v.add(P(l, r, i))
    }
    v.sortWith(compareBy(
        {it.l}, {it.r}
    ))
    var ans = Array(n) {i -> -1}
    var mx = -1
    var was = false
    for (i in 0 until n){
        if (v[i].l > mx && i > 0){
            for (j in i until n) ans[v[j].ind] = 2
            was = true
            break
        }
        mx = maxOf(mx, v[i].r)
        ans[v[i].ind] = 1
    }
    if (!was){
        println(-1)
        return
    }
    for (i in 0 until n){
        print(ans[i])
        print(" ")
    }
    println()
}

fun main(){
    var t = reader.nextInt()
    for (i in 0 until t){
        solve()
    }

}