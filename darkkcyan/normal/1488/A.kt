fun main() {
    for (testcase in 1.. readLine()!!.toInt()) {
        var (x, y) = readLine()!!.split(' ').map { it.toLong () }
        var ans = 0L
        for (i in 10 downTo 0) {
            var pw = x
            for (t in 1..i) pw *= 10
            ans += y / pw
            y %= pw
        }
        ans += y
        println(ans)
    }
}