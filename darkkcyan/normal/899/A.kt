import java.io.*
import java.util.StringTokenizer

val bf = BufferedReader(InputStreamReader(System.`in`))
var st = StringTokenizer("")

fun nxtstring(): String {
  while (!st.hasMoreTokens()) st = StringTokenizer(bf.readLine())
  return st.nextToken()
}

fun nxtint() = nxtstring().toInt()

fun main(args: Array<String>) {
  val n = nxtint()
  val cnt = IntArray(3)
  for (i in 0 until n) {
    val u = nxtint()
    cnt[u]++
  }
  var ans = 0
  while (cnt[1] > 0 && cnt[2] > 0) {
    ++ans
    --cnt[1]
    --cnt[2]
  }
  while (cnt[1] >= 3) {
    ++ans
    cnt[1] -= 3
  }
  println(ans)
}