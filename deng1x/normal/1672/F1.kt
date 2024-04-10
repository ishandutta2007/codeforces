fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()!!.toInt()
        val a = readLine()!!.split(" ").map { it.toInt() }
        val countA = a.groupingBy { it }.eachCount()
        val maxOccur = countA.values.maxOrNull()!!

        val sortedAByCount = a.sortedBy { it }.sortedBy { countA[it] }
        val sortedIndexAByCount = a.indices.sortedBy { a[it] }.sortedBy { countA[a[it]] }

        // left shift sortedAByCount by maxOccur
        val shifted = sortedAByCount.drop(maxOccur) + sortedAByCount.take(maxOccur)

        val answer = Array(a.size) { 0 }
        sortedIndexAByCount.mapIndexed { index, i -> answer[i] = shifted[index] }
        println(answer.joinToString(" "))
    }
}