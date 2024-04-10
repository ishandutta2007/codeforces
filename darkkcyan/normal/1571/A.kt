fun main() {
    for (testcase in 1..readLine()!!.toInt()) {
        val s = readLine()!!.dropWhile {it == '='}
        if (s.length == 0) {
            println("=")
            continue
        }
        var all_ok = true
        for (i in s) {
            if (i == '=') continue
            if (i != s[0]) {
                all_ok = false
                break
            }
        }
        if (!all_ok) {
            println("?")
            continue
        }
        println(s[0])
    }
}