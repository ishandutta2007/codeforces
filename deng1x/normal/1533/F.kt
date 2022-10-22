import kotlin.math.min

fun main() {
    val s = readLine()!!

    val pos0 = IntArray(s.length + 1) { s.length }
    val pos1 = IntArray(s.length + 1) { s.length }
    val sum0 = IntArray(s.length + 1)
    val sum1 = IntArray(s.length + 1)
    var cnt0 = 0
    var cnt1 = 0
    for (i in s.indices) {
        when (s[i]) {
            '0' -> {
                pos0[cnt0++] = i
                sum0[i] = 1
            }
            '1' -> {
                pos1[cnt1++] = i
                sum1[i] = 1
            }
        }
        if (i != 0) {
            sum0[i] += sum0[i - 1]
            sum1[i] += sum1[i - 1]
        }
    }
    sum0[s.length] = sum0[s.length - 1]
    sum1[s.length] = sum1[s.length - 1]

    val answer = mutableListOf<Int>()
    for (i in s.indices) {
        val k = i + 1
        var j0 = 0
        var j1 = 0
        var now = 0

        while (!(pos0[j0] == s.length && pos1[j1] == s.length)) {
            j0 = min(j0 + k, s.length)
            j1 = min(j1 + k, s.length)

            if (pos0[j0] < pos1[j1]) {
                j0 = min(sum0[pos1[j1]], s.length)
            } else if (pos0[j0] > pos1[j1]) {
                j1 = min(sum1[pos0[j0]], s.length)
            }

            ++now
        }

        answer.add(now)
    }

    println(answer.joinToString(" "))
}