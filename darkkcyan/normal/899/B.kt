import java.io.*
import java.util.StringTokenizer

val err = System.err
val bf = BufferedReader(InputStreamReader(System.`in`))
var st = StringTokenizer("")

fun nxtstring(): String {
  while (!st.hasMoreTokens()) st = StringTokenizer(bf.readLine())
  return st.nextToken()
}

fun nxtint() = nxtstring().toInt()

fun genyear(leap: Boolean) = intArrayOf(
  31, 28 + if (leap) 1 else 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
)

fun main(args: Array<String>) {
  val n = nxtint()
  val a = IntArray(n)
  for (i in 0 until n) a[i] = nxtint()
  val dat = IntArray(12 * 8)
  var day = 0
  for (year in 0 until 8) {
    for (i in genyear(year == 3)) {
      dat[day++] = i
      //err.printf("%d ", i)
    }
    //err.println()
  }
  for (i in 0 until dat.size - n) {
    val b = dat.copyOfRange(i, i + n)
    //for (y in b) err.printf("%d ", y)
    //err.println()
    if (b contentEquals a) {
      println("YES")
      System.exit(0)
    }
  }
  println("NO")
}