import java.util.Scanner

fun main() {
  val reader = Scanner(System.`in`)
  var T:Int = reader.nextInt()
  for (t in 1..T) {
    var a = reader.next()
    var b = reader.next()
    var i = 0
    var j = 0
    var flag = 1
    while (j < b.length) {
      if (i == a.length) { 
        flag = 0 
        break
      }
      if (b.get(j) == a.get(i)) {
        i = i + 1
        j = j + 1
        continue
      }
      if (b.get(j) == '-') {
        flag = 0
        break
      }
      if (i + 1 < a.length && a.get(i + 1) == '-') {
        i = i + 2
      }
      else { 
        flag = 0
break
 }
      j = j + 1
    }
    if (flag == 1 && i == a.length && j == b.length) {println("YES")}
    else {println("NO")}
  }
}