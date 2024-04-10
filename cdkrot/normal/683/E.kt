import kotlin.collections.set
import java.util.*


fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    var use:Array<Boolean> = Array<Boolean>(n, {i -> false})
    var arr:MutableList<Int> = mutableListOf<Int>()
    
    val tmp = readLine()!!.split(' ').map(String::toInt).filterTo(arr, {elem -> true})

    var out: MutableList<Int> = mutableListOf<Int>()
    
    var smurf = Array<Int>(n, {i -> 0})
    
    for (z in 1..n) {
        var best = -1
        for (i in 0..n-1) {
            if (!use[i] && arr[i] == smurf[i]) {
                best = i
                break
            }
        }
        if (best == -1) {
            break
        }
        out.add(best)
        use[best] = true
        for (i in 0..best) {
            smurf[i] += 1
        }
    }
    var ans = ""
    for (elem in out)
        ans = ans + (elem + 1) + " "
    println(ans)

}