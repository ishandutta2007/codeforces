import java.lang.Math.max
import java.lang.Math.min
import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints


fun main(args: Array<String>) {
    val n = readInt()
    val ts = TreeMap<Int, Int>()

    val times = readInts().toIntArray()
    var ans = 0
    for (time in times) {
        var itr = ts.higherKey(time)
        var cnt = 0
        while (itr != null) {
            cnt += ts.get(itr)!!
            if (cnt >= 3)
                break
            itr = ts.higherKey(itr)
        }
        if (cnt >= 2) ans += 1
        if (ts.get(time) != null) {
            ts.put(time, ts.get(time)!! + 1)
        } else {
            ts.put(time, 1)
        }
    }
    println(ans)
}