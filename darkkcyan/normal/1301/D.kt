fun main() {
    val (n, m, k) = readLine()!!.split(' ').map { it.toInt() }
    val gen_seq = sequence {
        if (m > 1) {
            yield(m - 1 to "R")
            yield(m - 1 to "L")
        }
        for (i in 1 until n) {
            yield(1 to "D")
            if (m > 1) {
                yield(m - 1 to "RUD")
                yield(m - 1 to "L")
            }
        }
        if (n > 1) yield(n - 1 to "U")
    }
    
    var total = 0
    val ans = MutableList(0) { 0 to "" }
    for (x in gen_seq) {
        if (total + x.first * x.second.length <= k) {
            ans.add(x)
            total += x.first * x.second.length
            continue
        }
        val d = (k - total) / x.second.length
        val rem = (k - total) % x.second.length
        if (d > 0) ans.add(d to x.second)
        if (rem > 0) ans.add(1 to x.second.substring(0, rem))
        total = k
        break
    }
    if (total < k) {
        println("NO")
    } else {
        println("YES")
        println(ans.size)
        println(ans.map { (u, v) -> "$u $v" }.joinToString("\n"))
    }
}