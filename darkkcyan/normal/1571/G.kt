import java.util.*

fun main() {
    val (n, m) = readLine()!!.split(' ').map{it.toInt()}
    
    val events = Array(m + n + 100) {MutableList<Pair<Int, Long>>(0) { 0 to 0 } }
    
    for (i in 1..n) {
        val k = readLine()!!.toInt()
        val a = readLine()!!.trim().split(' ').map {it.toLong()}.reversed()
        val b = readLine()!!.trim().split(' ').map {it.toInt()}.reversed()
        for (f in 0 until k) {
            val pos = i - (m - b[f]) - 1
            // println("i = $i, pos = $pos, b[f] = ${b[f]}, a[f] = ${a[f]}")  
            if (pos >= 0) {
                events[pos].add(i to a[f])
            }
        }
    }
    
    val ds = TreeMap<Int, Long>()
    ds[0] = 0
    for (pos in events.indices) {
        // println("pos = $pos")   
        events[pos].reverse() 
        for ((id, a) in events[pos]) {
            val b = id - pos - 1
            assert(b >= 0)
            var et = ds.floorEntry(b)!!
            val v = et.value + a
            // println("id = $id b = $b, v = $v, et = ${et.key}")   
            ds[b] = v
            
            while (true) {
                val nxt = ds.ceilingEntry(b + 1)
                if ((nxt?.value ?: v + 1) > v) break
                ds.remove(nxt.key)
            }
            // println(ds)   
        }
    }
    
    var ans = 0L
    for ((_, v) in ds) {
        ans = ans.coerceAtLeast(v)
    }
    println(ans)
}