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

var s = ""
var n = 0
var zeven = IntArray(200200)
var zodd = IntArray(200200)
var oeven = IntArray(200200)
var oodd = IntArray(200200)

fun main() {
    var TT = readInt()
    while (TT-- != 0) {
        s = readLn()
        n = s.length
        zeven[0] = 0
        zodd[0] = 0
        oeven[0] = 0
        oodd[0] = 0
        for (i in 0..(n-1)) {
            zeven[i+1] = zeven[i]
            zodd[i+1] = zodd[i]
            oeven[i+1] = oeven[i]
            oodd[i+1] = oodd[i]
            if (i%2 == 0) {
                if (s[i] == '0') {
                    zeven[i+1] += 1
                }
                if (s[i] == '1') {
                    oeven[i+1] += 1
                }
            } else {
                if (s[i] == '0') {
                    zodd[i+1] += 1
                }
                if (s[i] == '1') {
                    oodd[i+1] += 1
                }
            }
        }
        var ans = 0L
        for (i in 1..n) {
            var lo = i
            var hi = n
            while (lo < hi) {
                var mid = (lo+hi+1)/2
                var ze = (zeven[mid] - zeven[i-1]) > 0
                var zo = (zodd[mid] - zodd[i-1]) > 0
                var oe = (oeven[mid] - oeven[i-1]) > 0
                var oo = (oodd[mid] - oodd[i-1]) > 0
                if ((oe && oo)
                ||  (oe && ze)
                ||  (oo && oe)
                ||  (oo && zo)
                ||  (ze && zo)
                ||  (ze && oe)
                ||  (zo && ze)
                ||  (zo && oo)) {
                    hi = mid-1
                } else {
                    lo = mid
                }
            }
            ans += lo-i+1
        }
        println(ans)
    }
}