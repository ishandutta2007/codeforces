import java.io.*
import java.util.*

private fun readWords() = readLine()!!.split(" ")

fun main() {
    if (System.getProperty("ONLINE_JUDGE") == null) {
        System.setIn(FileInputStream(File("test.inp")))
        System.setOut(PrintStream(File("test.out")))
    }

    for (testcase in 0 until readLine()!!.toInt()) {
        var (n, k) = readWords().map(String::toInt)
        val a = readWords().map(String::toInt).withIndex()
            .sortedBy { it.value }
            .mapIndexed{ curId, (orgId, value) -> IndexedValue(orgId, value - curId)}

        val b = a.toMutableList()
        for (i in 1 .. n) {
            val diff = (
                    if (i == n) Int.MAX_VALUE
                    else (a[i].value - a[i - 1].value)
            )
            if (diff.toLong() * i < k) {
                k -= diff * i
                continue
            }
            var left = k % i
            for (f in i - 1 downTo 0) {
                val newVal = a[i - 1].value + k / i + (if (left > 0) 1 else 0)
                left--
                b[f] = IndexedValue(b[f].index, newVal)
            }
            break
        }
        println(b.mapIndexed() { curId, (orgId, value) ->
            IndexedValue(orgId, value - a[curId].value)}
            .sortedBy(IndexedValue<Int>::index)
            .joinToString(" ") { "${it.value}" }
        )
    }

}