import java.lang.Math.abs

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    readInt()
    val a = readInts().map { x -> abs(x) }.sorted()
    var ans = 0L
    for ((i, x) in a.withIndex()) {
        //var pos = a.binarySearch { if (it < x*2+1) -1 else if (it > x*2+1) 1 else 0 }
        var (lo, hi) = Pair(i, a.size)
        while (hi-lo>1){
            val mid = (lo+hi) shr 1
            if (a[mid] <= 2*x)
                lo = mid
            else
                hi = mid
        }
        /*if (pos < 0) {
            pos += 1
            pos = -pos
        }*/
        ans += hi - i - 1
    }
    println(ans)
}