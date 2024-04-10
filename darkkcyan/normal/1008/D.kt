import java.io.*
import java.util.*
val out = PrintWriter(System.out, false)
val bf = BufferedReader(InputStreamReader(System.`in`))
var stok = StringTokenizer("")
fun read(): String {
    while (!stok.hasMoreTokens()) stok = StringTokenizer(bf.readLine())
    return stok.nextToken()
}

fun Boolean.toInt() = if (this) 1 else 0
fun gcd(u: Int, v: Int): Int = if (v == 0) u else gcd(v, u % v)

val bitArr = Array(8) {
    val ans = ArrayList<Int>()
    for (i in 0 until 3) if (((it shr i) and 1) == 1) ans.add(i)
    ans
}

fun main() {
    val maxn = 101010
    val divs = IntArray(maxn)
    for (i in 1 until maxn) {
        for (f in i until maxn step i) {
            ++divs[f]
        }
    }

    val cases = HashSet<Map<Int, Int>>()
    for (i in 0 until 4) for (f in 0 until 4) for (g in 0 until 4) {
        val cntGroup = HashMap<Int, Int>()
        val idx = arrayOf((i * 2) or 0b001, g or 0b100, ((f or (f * 2)) and 0b101) or 0b010)
        for (v in idx) {
            cntGroup[v] = (cntGroup[v] ?: 0) + 1
        }
        cases.add(cntGroup)
    }

    val t = read().toInt()
    for (testcase in 1..t) {
        val inp = IntArray(3) { read().toInt() }
        val cntDivsJoin = bitArr.map{ it.map(inp::get).fold(0, ::gcd) }.map(divs::get).toIntArray()
        val cntDivsSeparate = IntArray(8) {-1}
        fun getDivsSeparate(mask: Int): Int {
            if (cntDivsSeparate[mask] != -1) return cntDivsSeparate[mask]
            cntDivsSeparate[mask] = cntDivsJoin[mask]
            for (i in mask + 1 until 8) {
                if ((i and mask) == mask) cntDivsSeparate[mask] -= getDivsSeparate(i)
            }
            return cntDivsSeparate[mask]
        }
        getDivsSeparate(0)
        var ans = 0L
        for (cntGroup in cases) {
            val s = cntGroup.entries.fold(1L) { sum, (id, case) ->
                val value = cntDivsSeparate[id]
                sum * when (case) {
                    1 -> value.toLong()
                    2 -> 1L * value * (value + 1) / 2
                    3 -> (value.toLong() * (value + 1) * (2 * value + 1) / 6+ value.toLong() * (value + 1) / 2) / 2
                    else -> 1L
                }
            }
//            System.err.println("$i $f $g ${cntGroup.joinToString(",")} $s")
            ans += s
        }
        out.println(ans)
    }
    out.flush()
}