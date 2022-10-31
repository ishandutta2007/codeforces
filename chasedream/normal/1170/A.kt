
import java.lang.Math.max
import java.lang.Math.min
import java.util.*

var scanner = Scanner(System.`in`)

fun readInt(): Int = scanner.nextInt()
fun readString(): String = scanner.next()

fun main() {
  var T = readInt()
  (1..T).forEach { _ -> run {
    var a = readInt()
    var b = readInt()
    println("${min(a-1,b-1)} 1 ${max(a,b)-min(a-1,b-1)}")
  } }
}