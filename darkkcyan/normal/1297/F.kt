import java.io.*
import java.util.*

private fun readWords() = readLine()!!.split(" ")

fun main() {
    if (System.getProperty("ONLINE_JUDGE") == null) {
        System.setIn(FileInputStream(File("test.inp")))
        System.setOut(PrintStream(File("test.out")))
    }

    class Range(args: List<Int>) : Comparable<Range> {
        var from = args[0]
        var to = args[1]

        override fun compareTo(other: Range): Int {
            if (to == other.to) return from.compareTo(other.from)
            return to.compareTo(other.to)
        }

        fun pack(): Long {
            return (from.toLong() shl 32) + to.toLong()
        }
    }

    for (testcase in 0 until readLine()!!.toInt()) {
        val (n, m) = readWords().map(String::toInt)
        val a = Array(n) {
            Range(readWords().map(String::toInt))
        }.withIndex().sortedBy { (_, value) -> value.pack() }

        val ans = IntArray(n) {0}

        var prevDay = -1
        val prio = TreeSet<IndexedValue<Range>>((compareBy<IndexedValue<Range>> { it.value }).thenBy{ it.index })

        var outOfSchedule = 0
        fun reduce() {
            for (i in 0 until m) {
                if (prio.size == 0) break
                val cur = prio.first()
                prio.remove(cur)
                ans[cur.index] = prevDay
                outOfSchedule = Math.max(outOfSchedule, prevDay - cur.value.to)
            }
        }
        for (it in a) {
            val (index, value) = it
            while (prevDay < value.from && prio.size > 0) {
                reduce()
                ++prevDay
            }
            prevDay = value.from
            prio.add(it)
        }
        while (prio.size > 0) {
            reduce()
            ++prevDay
        }

        println(outOfSchedule)
        println(ans.joinToString(" "))
    }
}