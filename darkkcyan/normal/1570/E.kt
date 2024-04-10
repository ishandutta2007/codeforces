fun main() {
    for (testcase in 1..readLine()!!.toInt()) {
        val s = readLine()!!
        val ans = s.dropWhile { it == '0' }.dropLastWhile { it == '0' }.count {it == '0'}
        println(ans)
    }
}