fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map{it.toInt()}.sorted()
    var ans = 0
    for (i in 0 until n step 2) {
        ans += a[i + 1] - a[i]
    }
    println(ans)
}