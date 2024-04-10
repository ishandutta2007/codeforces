import java.util.*
import kotlin.collections.HashMap

var scanner = Scanner(System.`in`)

fun readInt(): Int = scanner.nextInt()
fun readString(): String = scanner.next()

fun main() {
  val T = readLine()!!.toInt()
  repeat(T) {
    var s = readLine()!!
    var t = readLine()!!
    
    var ok = true
    var i = 0
    var j = 0
    while (i < s.length && j < t.length && ok) {
      if (s[i] == t[j]) {
        i++
        j++
      }
      else if (s[i] == '-' && i + 1 < s.length && s[i + 1] == '-' && t[j] == '+') {
        i += 2
        j++ 
      }
      else {
        ok = false
      }
    }
    
    println(if (ok && i == s.length && j == t.length) "YES" else "NO")
  }
}