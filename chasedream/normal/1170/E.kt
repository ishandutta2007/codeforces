import java.util.*
import kotlin.collections.HashMap

var scanner = Scanner(System.`in`)

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readLong() = readLn().toLong()
fun readStrings() = readLn().split(' ')
fun readInts() = readStrings().map { it.toInt() }
fun readDoubles() = readStrings().map { it.toDouble() }
fun readLongs() = readStrings().map { it.toLong() }

fun main() {
  val (n, m) = readInts()
  val a = readInts().toIntArray()
  val q = readInt()
  val b = IntArray(4 * a.size)
  
  fun build(u: Int, l: Int, r: Int): Int {
    val s = if (l == r) {
      a[l]
    } else {
      val mid = (l + r) / 2
      build(2 * u + 1, l, mid) + build(2 * u + 2, mid + 1, r)
    }
    b[u] = s
    return s
  }
  
  build(0, 0, n - 1)
  val ans = List(q) {
    val w = readInts().drop(1) + (m + 1)
    if (solve(n, m, b, w)) "YES" else "NO"
  }.joinToString("\n")
  println(ans)
}

private fun solve(n: Int, m: Int, b: IntArray, w: List <Int> ): Boolean {
  var i = 0
  var rev = 0
  var pp = 0
  
  fun query(u: Int, l: Int, r: Int, i: Int): Int {
    if (l == i && rev >= b[u]) {
      rev -= b[u]
      return r + 1
    }
    if (l == r) return i
    val mid = (l + r) / 2
    if (i > mid) return query(2 * u + 2, mid + 1, r, i)
    val j = query(2 * u + 1, l, mid, i)
    if (j <= mid) return j
    return query(2 * u + 2, mid + 1, r, mid + 1)
  }
  
  for (adj in w) {
    rev = adj - pp - 1
    i = query(0, 0, n - 1, i)
    if (i >= n) return true
    pp = adj
  }
  return false
}