import java.io.*
import java.util.*

private fun readWords() = readLine()!!.split(" ")

fun main() {
    if (System.getProperty("ONLINE_JUDGE") == null) {
        System.setIn(FileInputStream(File("test.inp")))
        System.setOut(PrintStream(File("test.out")))
    }

    for (testcase in 0 until readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val add = TreeMap<Int, MutableList<Int>>()
        val rem = TreeMap<Int, MutableList<Int>>()
        val values = TreeSet<Int>()

        for (i in 0 until n) {
            var (first, last) = readWords().map {it.toInt()}
            last++
            values.add(first)
            values.add(last)
            add.putIfAbsent(first, mutableListOf())
            rem.putIfAbsent(last, mutableListOf())
            add[first]!!.add(i)
            rem[last]!!.add(i)
        }

        var ans = -1
        val having = TreeSet<Int>()
        for (i in values) {
            if (add.containsKey(i)) {
                add[i]!!.forEach { having.add(it) }
            }
            if (rem.containsKey(i)) {
                rem[i]!!.forEach { having.remove(it) }
            }
            if (having.size != 1) continue
            ans = i
            break
        }
        println(ans)

    }

}