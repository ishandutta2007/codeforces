fun main() {
    for (testcase in 1..readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map{it.toInt()}
        val cmd = readLine()!!.trim()
        var r = 0
        var c = 0
        var min_r = 0
        var min_c = 0
        var max_r = 0
        var max_c = 0
        for (ch in cmd) {
            when (ch) {
                'R' -> {
                    c++
                    if (c > max_c) {
                        if (c - min_c + 1 > m) break
                        max_c = c
                    }
                }
                'L' -> {
                    c--
                    if (c < min_c) {
                        if (max_c - c + 1 > m) break
                        min_c = c
                    }
                }
                'U' -> {
                    r--
                    if (r < min_r) {
                        if (max_r - r + 1 > n) break
                        min_r = r
                    }
                }
                'D' -> {
                    r++
                    if (r > max_r) {
                        if (r - min_r + 1 > n) break
                        max_r = r
                    }
                }
            }
        }
        println("${(-min_r + 1).coerceAtMost(n)} ${(-min_c + 1).coerceAtMost(m)}")
    }
}