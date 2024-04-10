fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map { it.toInt() }
    val has = BooleanArray(1010)
    val ans = mutableListOf<Int>()
    for (i in a.reversed()) {
        if (has[i]) continue
        has[i] = true
        ans.add(i)
    }
    println(ans.size)
    println(ans.reversed().joinToString(" "))
}