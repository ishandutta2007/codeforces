fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toLong)
    var mx = LongArray(2)
    a.forEach {
        var cur = it
        for (f in mx.indices) {
            if (mx[f] < cur) {
                val t = cur
                cur = mx[f]
                mx[f] = t
            }
        }
    }

    val sum = a.reduce{u, v -> u + v}
    val ans = ArrayList<Int>()
    for ((i, v) in a.withIndex()) {
        val rest_sum = sum - v
        val cur_mx = if (v == mx[0]) mx[1] else mx[0]
        if (cur_mx * 2 == rest_sum) {
            ans.add(i + 1)
        }
    }
    println(ans.size)
    println(ans.joinToString(" "))
}