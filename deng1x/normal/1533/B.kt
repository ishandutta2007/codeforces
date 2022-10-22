fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val array = readLine()!!.split(" ").map { it.toInt() }
        var yes = false
        for (i in 1 until n) {
            if ((array[i - 1] + array[i]) % 2 == 0) {
                yes = true
                break
            }
        }
        println(if (yes) "YES" else "NO")
    }
}