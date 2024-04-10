fun main() {
    val (n, m) = readLine()!!.split(' ').map(String::toInt)
    var ans = HashMap<String, Int>()
    for (i in 1 .. n) {
        val s = readLine()!!.trim()
        ans[s] = (ans[s] ?: 0) + 1
    }

    val q = readLine()!!.toInt()
    for (query in 1..q) {
        val s = readLine()!!.trim()
        val canObtained = HashSet<String>()
        for (pos in 0..m) {
            canObtained.add(s.substring(0 until pos) + s.substring(pos + 1 .. m))
        }
        var curAns = 0
        for (newS in canObtained) {
            curAns += ans[newS] ?: 0
        }
        println(curAns)
    }
}