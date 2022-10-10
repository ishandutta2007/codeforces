private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readDouble() = readLn().toDouble()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }

fun main(args: Array<String>) {
    var t = readInt()

    while (t > 0) {
        t -= 1

        var n = readInt()
        if (n < 1000) {
            println(n)
        } else if (n < 999500) {
            var cnt = n / 1000

            if (n - cnt * 1000 < (cnt + 1) * 1000 - n) {
                print(cnt)
                print("K")
                println()
            } else {
                print(cnt + 1)
                print("K")
                println()
            }
        } else {
            var cnt = n / 1000000

            if (n - cnt * 1000000 < (cnt + 1) * 1000000 - n) {
                print(cnt)
                print("M")
                println()
            } else {
                print(cnt + 1)
                print("M")
                println()
            }
        }
    }
}