/**
 * Created by Administrator on 9/2/2019.
 */

// for (i in 1..n) {}
// for (i in 5 downTo 1)
// for (i in 1..5 step 2)
// println(n)
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    val n = readInt()
    val freq = mutableMapOf<String, Int>()
    val s = readLn()
    for (i in 0..(s.length-2)) {
        val cur = s.substring(i, i + 2)
        freq.put(cur, freq.getOrDefault(cur, 0) + 1)
    }
    var ans = ""
    var ansValue = 0
    for (k in freq.keys) {
        if (freq[k]!!.compareTo(ansValue) > 0) {
            ans = k
            ansValue = freq.get(k) as Int
        }
    }
    println(ans)
}