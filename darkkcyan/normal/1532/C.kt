fun main() {
    for (testcase in 1.. readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map(String::toInt)
        println((0 until k).map { (it + 'a'.toInt()).toChar() }.joinToString("").repeat((n + k - 1) / k).substring(0, n))
    }
}