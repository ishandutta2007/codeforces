import kotlin.math.*
import kotlin.collections.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }

fun gcd(a: Long, b: Long): Long {
    if (b == 0L) {
        return a
    }
    return gcd(b, a%b)
}

fun main() {
    var TT = readInt()
    while (TT-- != 0) {
        var n = readInt()
        var even = ArrayList<Long>();
        var odd = ArrayList<Long>();
        var nums = readInts()
        for (x in nums) {
            if (x%2 == 0) {
                even.add(x.toLong())
            } else {
                odd.add(x.toLong())
            }
        }
        var ans = 0
        for (i in 0..(odd.size-1)) {
            for (j in (i+1)..(odd.size-1)) {
                if (gcd(odd[i], odd[j]) > 1) {
                    ++ans
                }
            }
        }
        for (i in 0..(even.size-1)) {
            ans += n-i-1
        }
        println(ans)
    }
}