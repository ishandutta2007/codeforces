fun main() {
    for (testcase in 1..readLine()!!.toInt()) {
        val (a, b) = readLine()!!.split(' ').map(String::toInt)
        println(a + b)
    }
}