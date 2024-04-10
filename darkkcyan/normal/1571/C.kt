fun main() {
    for (testcase in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        var lo = 0
        var hi = 200000 + 10
        
        for (i in 1..n) {
            val (u, v, r) = readLine()!!.split(' ')
            var pivot = 0
            while (pivot < u.length && pivot < v.length && u[u.length - pivot - 1] == v[v.length - pivot - 1]) ++pivot
            if (r == "0") {
                lo = lo.coerceAtLeast(pivot + 1)
            } else {
                hi = hi.coerceAtMost(pivot)
            }
        }
        // println("$lo $hi") 
        println(0.coerceAtLeast(hi - lo + 1))
        println("${(lo..hi).joinToString(" ")}")
    }
}