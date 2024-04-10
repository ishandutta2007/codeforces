fun main() {
    val (n, m) = readLine()!!.split(' ').map {it.toInt()}
    val a = readLine()!!.split(' ').map {it.toLong()}.toList()

    data class Special(val u: Int, val v: Int, val w: Long)

    val special = Array(m) {
        val (u, v, w) = readLine()!!.split(' ').map {it.toLong()}
        Special(u.toInt() - 1, v.toInt() - 1, w)
    }.sortedBy { it.w }

    val sortedAId = IntArray(n) { it } .sortedBy { a[it] }

    val dsu = IntArray(n + 1) { -1 }

    fun findSet(u: Int): Int = if (dsu[u] < 0) { u } else { dsu[u] = findSet(dsu[u]); dsu[u] }

    fun join(u: Int, v: Int): Boolean {
        var du = findSet(u)
        var dv = findSet(v)
        if (du == dv) return false
        if (-dsu[du] < -dsu[dv]) {
            val t = du
            du = dv
            dv = t
        }
        dsu[du] += dsu[dv]
        dsu[dv] = du
        return true
    }

    val a0 = a[sortedAId[0]]
    var aPtr = 1
    var ans = 0L
    for ((u, v, w) in special) {
        while (aPtr < n && a0 + a[sortedAId[aPtr]] < w) {
            if (join(sortedAId[0], sortedAId[aPtr])) {
                ans += a0 + a[sortedAId[aPtr]]
            }
            ++aPtr
        }
        if (join(u, v)) {
            ans += w
        }
    }

    while (aPtr < n) {
        if (join(sortedAId[0], sortedAId[aPtr])) {
            ans += a0 + a[sortedAId[aPtr]]
        }
        ++aPtr
    }
    println(ans)
}