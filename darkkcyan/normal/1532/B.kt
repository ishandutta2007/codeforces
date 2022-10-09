fun main() {
    for (testcase in 1.. readLine()!!.toInt()) {
        val (a, b, k) = readLine()!!.split(' ').map(String::toLong)
        println(a * ((k + 1) / 2) - b * (k / 2))
    }
}