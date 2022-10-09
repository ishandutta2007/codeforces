fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)

    val cnt = IntArray(101)
    for (i in a) {
        cnt[i] = 1 - cnt[i]
    }

    var cur = -1
    var ans = 0
    for (i in 1 .. 100) {
        if (cnt[i] == 0) continue
        if (cur == -1) {
            cur = i
        } else {
            ans += i - cur
            cur = -1
        }
    }
    println(ans)
}