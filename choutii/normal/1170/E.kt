import java.util.*
private fun readInt() = readLine()!!.toInt()
private fun readStrings() = readLine()!!.split(" ")
private fun readInts() = readStrings().map{it.toInt()}
private fun readLongs() = readStrings().map{it.toLong()}


fun main() {
    var (n, m) = readInts()
    var arr = readInts()
    var q = readInt()
    var seg = IntArray(arr.size * 4 + 1)

    fun buildTree(p: Int, l: Int, r: Int): Int  {
        seg[p] = if (l == r) {
            arr[r]
        } else {
            buildTree(p * 2, l, (l + r) / 2) + buildTree(p * 2 + 1, (l + r) / 2 + 1, r)
        }
        return seg[p]
    }

    buildTree(1, 0, n - 1)
    repeat(q) {
        var w = readInts().drop(1) + (m + 1)
        var solvable = solve(n, m, seg, w)
        if (solvable)
            println("YES")
        else
            println("NO")
    }
}

fun solve(n: Int, m: Int, seg: IntArray, w:  List<Int>): Boolean {
    var remain = 0
    fun query(p: Int, l: Int, r:Int, x: Int): Int {
        if (l == x && remain >= seg[p]) {
            remain -= seg[p]
            return r + 1
        }
        if (l == r) return x
        if (x > (l + r) / 2)
            return query(p * 2 + 1, (l + r) / 2 + 1, r, x)
        val lch = query(p * 2, l, (l + r) / 2, x)
        if (lch <= (l + r) / 2)
            return lch
        else
            return query(p * 2 + 1, (l + r) / 2 + 1, r,(l + r) / 2 + 1)
    }
    var p = 0
    var i = 0
    for (q in w) {
        remain = q - p - 1
        i = query(1, 0, n - 1, i)
        if (i >= n) return true
        p = q;
    }
    return false
}