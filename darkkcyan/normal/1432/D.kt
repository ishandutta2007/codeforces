fun main() {
    val ntest = readLine()!!.toInt()
    for (testcase in 1..ntest) {
        val (n, a, b) = readLine()!!.split(" ").map(String::toInt)
        var base = "a".repeat(a - b + 1)
        for (i in 1 until b) {
            base += (i + 'a'.toInt()).toChar()
        }
        val ans = base.repeat(n / a) + base.substring(0, n % a)
        println(ans)
    }
}