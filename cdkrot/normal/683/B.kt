import kotlin.collections.sort
import java.util.*

fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    var arr = Array(n, {i -> Pair<Int, String>(0, "aba")})
    
    for (i in arr.indices) {
        val s = readLine()!!.split(' ')
        arr.set(i, Pair<Int, String>(s[1].toInt(), s[0]))
    }
    
    val lst = arr.sortedWith(object: Comparator<Pair<Int, String>> {
       override fun compare(x : Pair<Int, String>, y: Pair<Int, String>):Int {
            return x.first - y.first;
       }
    })

    for (elem in lst) {
        println(elem.second)
    }
}