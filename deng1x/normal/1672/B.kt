fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        if (s.last() == 'A') {
            println("NO")
            return@repeat
        }
        var countA = 0
        var countB = 0
        for (c in s) {
            if (c == 'A') {
                countA++
            } else {
                countB++
            }
            if (countA < countB) {
                println("NO")
                return@repeat
            }
        }
        println("YES")
    }
}