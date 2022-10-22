import kotlin.math.min

fun main() = repeat(readLine()!!.toInt()) {
    val n = readLine()!!.toInt()
    val s = readLine()!!.toCharArray()
    val a = readLine()!!

    var answer = 0
    for (i in 0..n - 4) {
        if (a[i] == '0') continue
        if ((i + 1 <= n - 4 && a[i + 1] == '1') || (i + 3 <= n - 4 && a[i + 3] == '1')) {
            answer = -1
            break
        }
        var now: Int
        if ((i - 2 >= 0 && a[i - 2] == '1') || (i + 2 <= n - 4 && a[i + 2] == '1')) {
            now = s.difference(i, "()()")
            s[i + 2] = '('
            s[i + 3] = ')'
        } else {
            now = min(s.difference(i, "(())"), s.difference(i, "()()"))
        }
        answer += now
    }

    println(answer)
}

private fun CharArray.difference(start: Int, another: String): Int {
    var result = 0
    for (i in another.indices) {
        result += if (this[i + start] != another[i]) 1 else 0
    }
    return result
}