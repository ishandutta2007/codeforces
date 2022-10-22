fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val a = readLine()!!.split(" ").map { it.toInt() }
        val b = readLine()!!.split(" ").map { it.toInt() }

        val map = mutableMapOf<Int, Int>()
        var j = b.size - 1
        for (i in b.size - 1 downTo 0) {
            if (i != b.size - 1 && b[i] == b[i + 1]) {
                map[b[i]] = map.getOrDefault(b[i], 0) + 1
                continue
            }
            while (j >= 0 && a[j] != b[i]) {
                map[a[j]] = map.getOrDefault(a[j], 0) - 1
                if (map[a[j]]!! < 0) {
                    println("NO")
                    return@repeat
                }
                j--
            }
            j--
        }
        println("YES")
    }
}