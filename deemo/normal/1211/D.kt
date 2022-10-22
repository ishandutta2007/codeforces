import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double

private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of long
private fun readDoubles() = readStrings().map { it.toDouble() } // list of double

private val OL = mutableListOf<String>()
private fun addOL(s: String){
    OL.add(s)
}
private fun outputRes() {
    println(OL.joinToString("\n"))
}

private val MAXN = 1e5.toInt()
private val MOD = 1e9.toInt() + 7

fun main() {
    var (n, a, b, k) = readInts()
    val mp = TreeMap<Int, Int>()
    val st = TreeSet<Int>()
    val r = readInts()
    for (x in r) {
        if (x in mp)
            mp[x] = mp[x]!! + 1
        else
            mp[x] = 1
    }

    var ans = 0
    for ((x, y) in mp) {
        if (x in st) continue

        val sec = mutableListOf<Int>()
        var temp = x
        while (temp in mp) {
            st.add(temp)
            sec.add(mp[temp]!!)
            temp *= k
        }

        val flag = a <= b
        if (flag) {
            sec.reverse()
            a = b.also { b = a }
            for (i in 0 until sec.size-1) {
                val g = minOf(sec[i]/a, sec[i+1]/b)
                ans += g
                sec[i+1] -= g*b
            }
            b = a.also {a = b}
        }
        else{
            for (i in 0 until sec.size-1) {
                val g = minOf(sec[i]/a, sec[i+1]/b)
                ans += g
                sec[i+1] -= g*b
            }

        }
    }
    println(ans)
}