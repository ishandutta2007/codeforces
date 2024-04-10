fun main() {
    for (testcase in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val (a, va) = readLine()!!.split(' ').map{it.toInt()}
        val (c, vc) = readLine()!!.split(' ').map{it.toInt()}
        val b = readLine()!!.toInt()
        println(vc.coerceAtMost(b - a + va))
    }
}