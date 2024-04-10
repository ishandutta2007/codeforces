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
        val n = readInt()
        val a = readInts().sorted()
        val mx = (n+1)/ 2
        var ans = mutableListOf<Int>()

        val c = IntArray(n)
        val _c = IntArray(n)
        var (cur, last) = Pair(0, -1)
        for (i in n-1 downTo 0) {
            if (a[i] == last)
                cur++
            else {
                cur = 1
                last = a[i]
            }
            c[i] = cur
        }
        cur = 0
        last = -1
        for (i in 0 until n) {
            if (a[i] == last)
                cur++
            else {
                cur = 1
                last = a[i]
            }
            _c[i] = cur
        }

        fun go(x: Int): Boolean {
            var tLast = c[n-x]
            val tBef = if (x < n && a[n-x] == a[n-x-1]) _c[n-x-1] else 0
            if (tBef == 0)
                tLast = 0

            val tl = (if (tLast == x) tLast -1 else tLast)
            if (tBef > 0 && (n-x)-tBef < tl) return false

            var temp = IntArray(x + x + 1) {-1}
            for (i in n-x until n) {
                temp[(i-(n-x))*2+1] = a[i]
            }
            var cur = 0
            var rem = tl
            var nd = x-1
            if (rem > 0) {
                for (i in 2..1e9.toInt() step 2) {
                    temp[i] = a[cur++]
                    nd--
                    if (--rem == 0)
                        break
                }
            }

            if (cur < n-x && a[cur] < a[n-x] && (n-x-cur-1) >= nd)
                temp[0] = a[cur++]
            for (i in 2..2*x step 2) {
                if (cur == n-x) break
                if (i == 2*x && a[cur] >= a[n-1]) break
                if (temp[i] == -1)
                    temp[i] = a[cur++]
            }
            if (temp.last() == -1)
                temp = temp.dropLast(1).toIntArray()
            if (temp[0] == -1)
                temp = temp.drop(1).toIntArray()
            ans = temp.toMutableList()
            return true
        }

        for (i in mx downTo 1)
            if (go(i))
                break
        addOL(ans.size.toString())
        addOL(ans.joinToString(" "))
    }
    outputRes()
}