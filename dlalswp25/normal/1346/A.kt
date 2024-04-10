fun main() {
    var t = readLine()!!.toInt()
    while (t > 0) {
        var (n, k) = readLine()!!.split(" ").map { it.toInt() }
        var n1 = n / (1 + k + k * k + k * k * k)
        println("$n1 ${n1 * k} ${n1 * k * k} ${n1 * k * k * k}")
        t--
    }
}