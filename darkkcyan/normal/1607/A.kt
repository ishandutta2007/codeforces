fun main() {
    for (testcase in 1..readLine()!!.toInt()) {
        val alpha = readLine()!!.trim()
        val pos = IntArray(26)
        for ((i, a) in alpha.withIndex()) {
            pos[a.toInt() - 'a'.toInt()] = i
        }
        val s = readLine()!!.trim()
        var ans = 0
        for (i in 1 until s.length) {
            ans += Math.abs(pos[s[i].toInt() - 'a'.toInt()] - pos[s[i - 1].toInt() - 'a'.toInt()])
        }
        println(ans)
    }
}