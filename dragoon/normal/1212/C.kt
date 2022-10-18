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

fun main(args: Array<String>) {
    val (n, k) = readInts()
    var a = readInts()
    a = a.sorted()
    var ans = -1
    if (k == n) ans = a[n - 1]
    else if (k == 0) {
        if (a[0] > 1) ans = 1
    }
    else if (k < n && a[k-1] != a[k]) {
        ans = a[k - 1]
    }
    println(ans)
    //a.sort()

}