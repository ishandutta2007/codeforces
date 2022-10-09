fun main() {
    val (n, m, d) = readLine()!!.split(' ').map(String::toInt)
    val c = readLine()!!.split(' ').map(String::toInt).toList()
    
    var s = c.sum() + (d - 1) * (m + 1)
    if (s < n) {
        println("NO")
        return ;
    }
    
    val slot = Array(m + 1) { d - 1 }
    var need_shrink = Math.max(0, s - n)
    for (i in 0 until slot.size) {
        val diff = Math.min(need_shrink, slot[i])
        need_shrink -= diff
        slot[i] -= diff
    }
    
    val ans = Array(n) {0}
    var pos = 0
    for (i in 0 until m) {
        pos += slot[i]
        for (f in 0 until c[i]) {
            ans[pos + f] = i + 1
        }
        pos += c[i]
    }
    println("YES")
    println(ans.joinToString(" "))
}