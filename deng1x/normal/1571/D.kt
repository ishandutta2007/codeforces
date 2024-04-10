import kotlin.math.max

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }

    val (f1, l1) = readLine()!!.split(" ").map { it.toInt() }

    val bothMap = mutableMapOf(Pair(f1, l1) to 1)
    val firstMap = mutableMapOf(f1 to 1)
    val lastMap = mutableMapOf(l1 to 1)

    repeat(m - 1) {
        val (first, last) = readLine()!!.split(" ").map { it.toInt() }
        bothMap[Pair(first, last)] = (bothMap[Pair(first, last)] ?: 0) + 1
        firstMap[first] = (firstMap[first] ?: 0) + 1
        lastMap[last] = (lastMap[last] ?: 0) + 1
    }

    var answer = 1
    for (i in 1..n) {
        for (j in 1..n) {
            if (i == j) continue

            answer = if (i == f1 && j == l1) {
                continue
            } else if (i == f1 || j == l1) {
                max(answer, bothMap.getOrDefault(Pair(i, j), 0) + 1)
            } else {
                max(
                    answer,
                    firstMap.getOrDefault(i, 0) + lastMap.getOrDefault(j, 0) - bothMap.getOrDefault(Pair(i, j), 0) + 1
                )
            }
        }
    }
    println(answer)
}