private fun readInt() = readLine()!!.toInt()
private fun readStrings() = readLine()!!.split(" ")
private fun readInts() = readStrings().map{it.toInt()}
private fun readLongs() = readStrings().map{it.toLong()}

fun main() {
    val n = readInt()
    val array = readInts()
    var mx1 = 0
    var mx2 = 0
    var ans = 0
    for (x in array) {
        if (x > mx1) {
            mx2 = mx1
            mx1 = x
        } else {
            if (x >= mx2) {
                mx2 = x
            } else
                ans += 1
        }
    }
    println(ans)
}