import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.*

val bf = BufferedReader(InputStreamReader(System.`in`))
var stok = StringTokenizer("")

fun read(): String {
    while (!stok.hasMoreTokens()) stok = StringTokenizer(bf.readLine())
    return stok.nextToken()
}

fun main() {
    val n = read().toInt()
    val k = read().toInt()
    val a = IntArray(n) { read().toInt() * 100 }
    val c = IntArray(n) { read().toInt() }

    val l2 = IntArray(n + 10)
    l2[1] = 0
    for (i in 2 until l2.size) l2[i] = l2[i / 2] + 1

    class SparseTable(x: IntArray, val biFn: (Int, Int) -> Int) {
        val tab: Array<IntArray> = Array(l2[x.size] + 1){IntArray(x.size)}

        init {
            tab[0] = x.copyOf()
            for (i in 0 until tab.size - 1) {
                for (f in 0 until x.size - (1 shl i))
                    tab[i + 1][f] = biFn.invoke(tab[i][f], tab[i][f + (1 shl i)])
            }
        }

        // [l; r)
        fun get(l: Int, r: Int): Int {
            val pw = l2[r - l]
            return biFn.invoke(tab[pw][l], tab[pw][r - (1 shl pw)])
        }
    }

    val max_a = SparseTable(a, ::max)
    val min_c = SparseTable(c, ::min)

    // [l; r)
    fun get_p(l: Int, r: Int) = min(max_a.get(l, r), min_c.get(l, r))

    val max_potential = IntArray(n)
    for (i in 0 until n) {
        var l = i + 1
        var r = n
        while (r - l > 1) {
            val mid = l + (r - l) / 2
            if (min_c.get(i, mid) < max_a.get(i, mid)) r = mid
            else l = mid
        }
        max_potential[i] = max(get_p(i, l), get_p(i, r))
//        println("$i $l $r ${max_potential[i]} ${max_a.get(i, l)} ${min_c.get(i, l)}")
    }

    max_potential.sort()
    var factor = k * 1.0 / n
    var ans = 0.0
    for ((i, value) in max_potential.slice(0..n - k).withIndex()) {
//        println("$i $value $factor")
        ans += value * factor
        val left = n - i
        factor *= (left - k) * 1.0 / (left - 1)
    }
    print("%.9f".format(ans))
}