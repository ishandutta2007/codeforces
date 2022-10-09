import java.io.*
import java.util.StringTokenizer

val err = System.err
val bf = BufferedReader(InputStreamReader(System.`in`))
var st = StringTokenizer("")
val ou = PrintWriter(System.`out`)

fun nxtstring(): String {
  while (!st.hasMoreTokens()) st = StringTokenizer(bf.readLine())
  return st.nextToken()
}

fun nxtint() = nxtstring().toInt()

fun main(args: Array<String>) {
  val n = nxtint()
  when (n % 4) {
    1, 2 -> ou.println(1)
    else -> ou.println(0)
  }
  val ans = ArrayList<Int>()
  if (n % 2 == 1) {
    ans.add(1)
    for (i in 2 .. n step 2) {
      if (i % 4 == 0) ans.add(i + 1)
      else ans.add(i)
    }
  } else for (i in 1 .. n step 2) {
    if (i % 4 == 1) ans.add(i)
    else ans.add(i + 1)
  }
  ou.printf("%d ", ans.size)
  for (i in ans) ou.printf("%d ", i)
  ou.flush()
}