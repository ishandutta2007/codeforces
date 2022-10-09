import java.io.*
import java.util.*

val maxn = 201010
val err = System.err
val bf = BufferedReader(InputStreamReader(System.`in`))
var st = StringTokenizer("")

fun nxtstring(): String {
  while (!st.hasMoreTokens()) st = StringTokenizer(bf.readLine())
  return st.nextToken()
}

fun nxtint() = nxtstring().toInt()

data class Dat(var len: Int, var pos: Int)
var se = TreeSet<Dat>(object: Comparator<Dat> {
  override fun compare(a: Dat, b: Dat): Int {
    if (a.len == b.len) return a.pos - b.pos
    return b.len - a.len
  }
})

var n = 0
val a = IntArray(maxn)
val dsu = IntArray(maxn)
val len = IntArray(maxn)
val last = IntArray(maxn)
val pre= IntArray(maxn)
val nxt = IntArray(maxn)
fun findp(u: Int): Int = if (u == dsu[u]) dsu[u] else findp(dsu[u])
fun join(cu: Int, cv: Int) {
  var u = findp(cu)
  var v = findp(cv)
  if (u == v) return
  if (u > v) u = v.also {v = u}
  //err.println("join $u $v")
  se.remove(Dat(len[u], u))
  se.remove(Dat(len[v], v))
  len[u] += len[v]
  dsu[v] = dsu[u]
  last[u] = last[v]
  se.add(Dat(len[u], u))
}

fun rem() {
  val t = se.pollFirst()
  var head = t.pos
  var tail = last[head]
  //err.printf("%d %d %d\n", len[head], head, tail)
  var u = pre[head]
  var v = nxt[tail]
  if (u != -1) nxt[u] = v
  if (v != n) pre[v] = u
  if (u == -1 || v == n) return
  if (a[u] != a[v]) return
  join(u, v)
}

fun main(args: Array<String>) {
  n = nxtint()
  for (i in 0 until n) {
    a[i] = nxtint()
    dsu[i] = i
    len[i] = 1
    last[i] = i
    se.add(Dat(1, i))
  }
  nxt[n - 1] = n
  pre[0] = -1
  for (i in 0 until n - 1) {
    nxt[i] = i + 1
    pre[i + 1] = i
  }
  for (i in 0 until n - 1) {
    if (a[i] != a[i + 1]) continue
    join(i, i + 1)
  }
  var ans = 0
  while (!se.isEmpty()) {
    rem()
    ++ans
  }
  println(ans)
}