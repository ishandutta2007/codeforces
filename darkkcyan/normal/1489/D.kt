fun main() {
    val n = readLine()!!.toInt()
    val s = Array(n) { readLine()!!.trim() }.sortedBy { it.length }
    for (i in 1 until n) {
        if (s[i].contains(s[i - 1])) continue
        println("NO")
        return
    }
    println("YES")
    s.forEach { println(it)}
}