fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }

    val map = mutableMapOf<String, Int>()
    repeat(n) {
        map[readLine()!!] = 1
    }

    val q = readLine()!!.toInt()
    repeat(q) {
        val s = readLine()!!
        var ans = 0

        val candidates = s.indices.map { s.take(it) + s.drop(it + 1) }.toSet()
        for (c in candidates) {
            ans += map.getOrDefault(c, 0)
        }
        println(ans)
    }
}