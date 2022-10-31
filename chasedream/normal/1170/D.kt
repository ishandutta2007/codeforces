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
  val m = readInt()
  val b = readInts()
  
  var n = b.count {
    it == -1
  }
  
  var decoded = List(n) {
    mutableListOf <Int> ()
  }
  var queue = decoded.toCollection(ArrayDeque())
  
  for (i in b) {
    var fuck = queue.remove()
    if (i != -1) {
      fuck.add(i)
      queue.add(fuck)
    }
  }
  
  output {
    println(n)
    for (d in decoded) {
      println("${d.size} ${d.joinToString(" ")}")
    }
  }
}

class Output {
  private val sb = StringBuilder()
  fun print(o: Any?) { sb.append(o) }
  fun println(o: Any?) { sb.append(o).append('\n') }
  fun println() { sb.append('\n') }
  fun nowPrint() { kotlin.io.print(sb) }
}
fun output(block: Output.() -> Unit) { 
  Output().apply(block).nowPrint() 
}