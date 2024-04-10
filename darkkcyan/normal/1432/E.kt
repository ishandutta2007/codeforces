fun main() {
    val ntest = readLine()!!.toInt()
    for (testcase in 1..ntest) {
        val curLine = readLine()!!.split(" ")
        val n = curLine[0].toInt()
        var k = curLine[1].toLong()
        val s = readLine()!!.trim()
        val pos0 = mutableListOf(-1)
        for (i in 0 until n) {
            if (s[i] == '0') pos0.add(i)
        }
        
        for (i in 1 until pos0.size) {
            if (k == 0L) break
            val diff = pos0[i] - pos0[i - 1] - 1
            val step = Math.min(diff.toLong(), k)
            k -= step
            pos0[i] -= step.toInt()
        }
        var ans = Array(n) { '1' }
        pos0.subList(1, pos0.size).forEach { ans[it] = '0' }
        println(ans.joinToString(""))
    }
}