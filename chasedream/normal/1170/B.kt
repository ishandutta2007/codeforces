import java.util.*
import kotlin.collections.HashMap

var scanner = Scanner(System.`in`)

fun readInt(): Int = scanner.nextInt()
fun readString(): String = scanner.next()


fun lowbit(x: Int): Int = x.and(-x)

var a = IntArray(200005)
var c = IntArray(200005)
var hsh = HashMap <Int, Int> ()

fun update(pos: Int, n: Int, v: Int) {
  var x = pos
  while (x <= n) {
    c[x] += v
    x += lowbit(x) 
  }
}

fun query(pos: Int): Int {
  var ans = 0
  var x = pos
  while (x > 0) {
    ans += c[x]
    x -= lowbit(x) 
  }
  return ans
}

fun pre(n: Int) {
  var tmp = a.clone()
  tmp.sort(1, n + 1)
  
  (1..n).forEach {
    hsh[tmp[it]] = it
  }
  (1..n).forEach {
    a[it] = hsh[a[it]]!!
  }
}

fun main() {
  var n = readInt()  
  (1..n).forEach {
    a[it] = readInt()
  }
  pre(n)
  var ans = 0
  for (i in 1..n) {
    if (query(a[i]) + 2 < i) ans++
    update(a[i], n, 1)
  }
  println(ans)
}