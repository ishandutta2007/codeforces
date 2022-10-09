import java.io.*
import java.util.*

private fun readWords() = readLine()!!.split(" ")

fun main() {
    if (System.getProperty("ONLINE_JUDGE") == null) {
        System.setIn(FileInputStream(File("test.inp")))
        System.setOut(PrintStream(File("test.out")))
    }

    for (testcase in 0 until readLine()!!.toInt()) {
        val (n, k) = readWords().map(String::toInt)
        val gr = Array<TreeSet<Int>>(n) { TreeSet() }
        for (edge in 0 until n - 1) {
            val (u, v) = readWords().map {it.toInt() - 1}
            gr[u].add(v)
            gr[v].add(u)
        }


        val prio = MutableList(0){0}
        for (i in 0 until n) {
            if (gr[i].size == 1) prio.add(i)
        }
        if (prio.size < k) {
            println("No")
            continue
        }
        println("Yes")
        val removed = HashSet<Int>()

        while (prio.size > k) {
            val u = prio.last()
            prio.removeAt(prio.lastIndex)
            removed.add(u)
            for (v in gr[u]) {
                gr[v].remove(u)
                if (gr[v].size != 1) continue
                prio.add(v)
            }
        }
        println(n - removed.size)
        for (i in 0 until n) {
            if (!removed.contains(i)) print("${i + 1} ")
        }
        println()
    }

}