fun main() {
    val (n, m) = readLine()!!.split(' ').map {it.toInt()}
    var cnt_both = Array(n + 1) { IntArray(n + 1) }
    var cnt_first = IntArray(n + 1)
    var cnt_last = IntArray(n + 1)
    val (mf, ml) = readLine()!!.split(' ' ).map {it.toInt()}
    cnt_both[mf][ml] ++
    cnt_first[mf] ++
    cnt_last[ml] ++
    for (i in 2..m) {
        val (f, l) = readLine()!!.split(' ').map {it.toInt()}
        cnt_both[f][l]++
        cnt_first[f] ++
        cnt_last[l]++
    }
    
    var rest = 1
    for (f in 1..n) {
        for (l in 1..n) {
            if (l == f) continue
            var r1 = cnt_both[f][l]
            var r2 = cnt_first[f] + cnt_last[l] - cnt_both[f][l]
            if (mf == f && ml == l) {
                continue
            }
            if (mf == f || ml == l) {
                rest = rest.coerceAtLeast(r1 + 1)
            } else {
                rest = rest.coerceAtLeast(r2 + 1)
            }
        }
    }
    println(rest)
}