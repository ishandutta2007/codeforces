import java.util.Scanner

fun main() {
  val reader = Scanner(System.`in`)
  var n:Int = reader.nextInt()
  var mx = -1
  var mx2 = -1
  var cnt = 0
  for (i in 1..n) {
    var a = reader.nextInt()
    if (mx2 > a) {
      cnt = cnt + 1
    }
    if (mx < a) {
      mx2 = mx
      mx = a
    }
    else {
      if (mx2 < a) {
        mx2 = a
      }
    }
  }
  println(cnt)
}