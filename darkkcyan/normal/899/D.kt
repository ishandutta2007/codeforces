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

var n: Long = 0
val p10 = LongArray(11)

fun findmax9(): Int {
  var ans = 0
  var num = 0L
  while (true) {
    val ldn = n / p10[ans] % 10
    val od = 9 - ldn
    num += p10[ans] * od
    if (num > n) break
    ++ans
  }
  return ans
}

fun main(args: Array<String>) {
  n = nxtint().toLong()
  p10[0] = 1
  for (i in 1..10) p10[i] = p10[i - 1] * 10
  val max9 = findmax9()
  if (max9 == 0) {
    println(n * (n - 1) / 2)
    return
  }
  var t = 0
  var ans = 0L
  while (true) {
    var num = p10[max9] * t + p10[max9] - 1
    ++t
    var l = 1
    var r = n.toInt()
    while (l < r) {
      var mid: Int = l + (r - l) / 2
      if (num - mid > n) l = mid + 1
      else r = mid
    }
    //err.printf("%d %d\n", num, l)
    if (num - l <= l || num - l > n) break
    val cnt: Long = num - l - l + 1
    ans += cnt / 2
  }
  println(ans)
}