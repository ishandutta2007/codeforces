
fun ask(w: Int): Int {
    println("? $w")
    System.out.flush()
    return readLine()!!.toInt()
}

fun answer(a: Int) {
    println("! $a")
    System.out.flush()
}

fun main() {
    val n = readLine()!!.toInt()
    var l = 1
    var r = 2000 * 2000 + 2000
    var totalLen = 0
    while (l <= r) {
        val m = (l + r) / 2
        if (ask(m) == 1) {
            totalLen = m
            r = m - 1
        } else {
            l = m + 1
        }
    }
    answer(
        (1..n).minOf {
            val w = totalLen / it
            val h = ask(w)
            if (h == 0) {
                Int.MAX_VALUE
            } else {
                h * w
            }
        })
}