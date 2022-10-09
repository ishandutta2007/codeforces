fun main() {
    readLine()!!
    val s = readLine()!!
    var t = 0
    var ans = ""
    for (i in 1..s.length + 1) {
        if (t >= s.length) break
        ans += s[t]
        t += i
    }
    println(ans)
}