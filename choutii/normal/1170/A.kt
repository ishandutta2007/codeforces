private fun readInt() = readLine()!!.toInt()
private fun readStrings() = readLine()!!.split(" ")
private fun readInts() = readStrings().map{it.toInt()}
private fun readLongs() = readStrings().map{it.toLong()}

fun main() {
    val q = readLine()!!.toInt()
    repeat(q) {
        var (x, y) = readLongs()
        x -= 2
        y -= 2
        val z = maxOf(x, y) - minOf(x, y)
        val sum = (x + y + z) / 2
        val a = sum - x
        val b = sum - y
        val c = sum - z
        println("${a + 1} ${b + 1} ${c + 1}")
    }
}