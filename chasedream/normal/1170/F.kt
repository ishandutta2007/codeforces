import java.util.*
import kotlin.collections.HashMap
 
var scanner = Scanner(System.`in`)
 
fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readLong() = readLn().toLong()
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readDoubles() = readStrings().map { it.toDouble() }
fun readLongs() = readStrings().map { it.toLong() }
 
fun main() {
  val (n, m, k) = readInts()
  var A = readLongs()
  var a = arrayListOf <Long> ()
  
  a.addAll(A)
  a.sort()
  
  var ans = (1e18).toLong()
  var id = 0
  var l: Long = 0
  var r: Long = 0
  for (i in 0..m-1) {
    l += a[i] - a[0]
  } 
  
  //  
  for (i in 0..n-m) {
    val mid = i + (m - 1) / 2
    
    while (id < mid) {
      if (r + (a[id + 1] - a[id]) * (id + 1 - i) <= k) {
        r += (a[id + 1] - a[id]) * (id + 1 - i)
        l -= (a[id + 1] - a[id]) * (i + m - 1 - id)
        id++
      } else break
    }
    
    //  
    if (id < mid) {
      var tmp: Long = (k - r) / (id + 1 - i)
      ans = minOf(ans, l + r + (2 * id + 2 - m - 2 * i) * tmp); // min 
    } else {
      ans = minOf(ans, l + r) // min 
    }
    //  
    if (i < n - m) { //  
      r -= a[id] - a[i]
      l += a[i + m] - a[id]
    }
  }
  println(ans)
}