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
    val t = readInt()
    repeat(t) {
        val (n, m) = readInts()
        val segs = mutableListOf<Pair<Int, Int>>()
        repeat(n) {
            val (a, b) = readInts()
            segs.add(a to b)
        }
        val sec = MutableList(n) {it}
        sec.sortBy { segs[it].first } //XXX

        var ptr = 0
        var i = 1
        val st = TreeSet<Pair<Int, Int>>(compareBy ({ it.first }, {it.second}))
        val ans = IntArray(n) {0}
        var z = 0
        while (i < 2e9.toInt()) {
            while (ptr < n && segs[sec[ptr]].first <= i) {
                st.add(segs[sec[ptr]].second to sec[ptr])
                ptr++
            }

            if (st.size == 0) {
                if (ptr == n) break
                i = segs[sec[ptr]].first
                continue
            }

            var rem = m
            while (rem > 0 && st.size > 0) {
                val x = st.first()
                st.remove(x)
                ans[x.second] = i
                z = maxOf(z, i - segs[x.second].second)
                rem--
            }

            i++
        }
        addOL("${z}")
        addOL(ans.joinToString(" "))
    }
    outputRes()
}