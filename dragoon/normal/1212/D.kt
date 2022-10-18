/**
 * Created by Administrator on 9/2/2019.
 */

// for (i in 1..n) {}
// for (i in 5 downTo 1)
// for (i in 1..5 step 2)
// println(n)
// val freq = mutableMapOf<String, Int>()
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of Longs

class Number(val n: Long, val num3: Int, val num2: Int)

fun main(args: Array<String>) {
    val n = readInt()
    val a = readLongs()
    var numbers = mutableListOf<Number>()
    for (i in a) {
        var num3 = 0
        var num2 = 0
        var temp = i
        while (temp % 3 == 0L || temp % 2 == 0L) {
            if (temp % 3 == 0L) {
                num3++
                temp /= 3
            }
            if (temp % 2 == 0L) {
                num2++
                temp /= 2
            }
        }
        numbers.add(Number(i, num3, num2))
    }
    numbers.sortWith(object: Comparator<Number>{
        override fun compare(o1: Number, o2: Number): Int = when {
            o1.num2 == o2.num2 -> o2.num3 - o1.num3
            else -> o1.num2 - o2.num2
        }
    })
    numbers.forEach{print("${it.n} ")}
}