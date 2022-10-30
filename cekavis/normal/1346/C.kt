import kotlin.math.min

fun main() {
    var t = readLine()!!.toInt()
    while(t-->0){
        val (n, k, x, y) = readLine()!!.split(' ').map { it.toLong() }
        var a = readLine()!!.split(' ').map { it.toLong() }
        var s = a.sum()
        var ans = a.map { if (it>k) x else 0 }.sum()
        a=a.sorted().reversed()
        for (i in 0 until n){
            if (s<=k*n){
                ans=min(ans, i*x+y)
                break
            }
            s-=a[i.toInt()]
        }
        println(ans)
    }
}