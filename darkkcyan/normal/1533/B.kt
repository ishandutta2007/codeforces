fun main() {
    for (testcase in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map(String::toInt)
        var ans = false
        for (i in 1 until n) {
            if ((a[i] - a[i - 1]) % 2 == 0) {
                ans = true
                break;
            }
        }
        println(if(ans) "YES" else "NO")
    }
}