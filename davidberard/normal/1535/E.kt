import kotlin.math.*
import kotlin.collections.*

fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInt() = readLn().toInt()
fun readInts() = readStrings().map { it.toInt() }
fun readLong() = readLn().toLong()
fun readLongs() = readStrings().map { it.toLong() }

fun gcd(a: Long, b: Long): Long {
    if (b == 0L) {
        return a
    }
    return gcd(b, a%b)
}

var N = 300300
var LG = 19
var par = Array<IntArray>(N, {_ -> IntArray(LG)})
var c = LongArray(N)
var a = LongArray(N)
var dep = IntArray(N)
//var totalCount = LongArray(N)
//var totalCost = LongArray(N)
var adj = Array<ArrayList<Int>>(N, {_ -> ArrayList<Int>()})

fun addBelow(u: Int, p: Int, ai: Long, ci: Long) {
    par[u][0] = p
    for (l in 0..(LG-2)) {
        par[u][l+1] = par[par[u][l]][l]
    }
    dep[u] = dep[p]+1;
    c[u] = ci
    a[u] = ai
    //totalCount[u] = totalCount[p] + ai
    //totalCost[u] = totalCost[p] + ai*ci
}

fun main() {
    var (q, a0, c0) = readInts()
    addBelow(1, 0, a0.toLong(), c0.toLong())
    for (qidx in 2..(q+1)) {
        var vals = readInts()
        when (vals[0]) {
            1 -> {
                var (_, pi, ai, ci) = vals
                addBelow(qidx, pi+1, ai.toLong(), ci.toLong())
            }
            2 -> {
                var (_, vi, wi) = vals
                ++vi
                var taken = 0
                var totcost = 0L
                while (taken < wi) {
                    var u = vi
                    for (l in (LG-1) downTo 0) {
                        if (a[par[u][l]] != 0L) {
                            u = par[u][l]
                        }
                    }
                    var take = min(a[u].toInt(), wi-taken)
                    taken += take
                    a[u] -= take.toLong()
                    totcost += take*c[u]
                    if (u == vi) {
                        break
                    }
                }
                println("$taken $totcost")
            }
        }
    }
}