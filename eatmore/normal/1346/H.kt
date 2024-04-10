import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun sort(a: IntArray, n: Int) {
    if (n == 0) {
        return
    }
    for (i in 1 until n) {
        var j = i
        val ca = a[i]
        do {
            val nj = j - 1 shr 1
            val na = a[nj]
            if (ca <= na) {
                break
            }
            a[j] = na
            j = nj
        } while (j != 0)
        a[j] = ca
    }
    var ca = a[0]
    for (i in n - 1 downTo 1) {
        var j = 0
        while ((j shl 1) + 2 + Int.MIN_VALUE < i + Int.MIN_VALUE) {
            j = j shl 1
            j += if (a[j + 2] > a[j + 1]) 2 else 1
        }
        if ((j shl 1) + 2 == i) {
            j = (j shl 1) + 1
        }
        var na = a[i]
        a[i] = ca
        ca = na
        while (j != 0 && a[j] < ca) {
            j = j - 1 shr 1
        }
        while (j != 0) {
            na = a[j]
            a[j] = ca
            ca = na
            j = j - 1 shr 1
        }
    }
    a[0] = ca
}

fun best(l: IntList?, max: Int): Int {
    if (l == null) {
        return -1
    }
    var p = Arrays.binarySearch(l.data, 0, l.size, max)
    if (p < 0) {
        p = p.inv() - 1
    }
    return if (p < 0) -1 else l.data[p]
}

fun solve() {
    val n = scanInt()
    val m = scanInt()
    val c = IntArray(n)
    val len = IntArray(n)
    for (i in 0 until n) {
        val l = scanInt()
        val r = scanInt()
        c[i] = l + r
        len[i] = r - l
    }
    val lens = arrayOfNulls<IntList>(2000002)
    for (i in 0 until m) {
        val l = scanInt()
        val r = scanInt()
        if (lens[l + r] == null) {
            lens[l + r] = IntList()
        }
        lens[l + r]!!.push(r - l)
    }
    for (l in lens) {
        if (l != null) {
            sort(l.data, l.size)
        }
    }
    for (i in 0 until n) {
        val cur = best(lens[c[i]], len[i])
        val left = best(lens[c[i] - 2], len[i] - 1)
        val right = best(lens[c[i] + 2], len[i] - 1)
        val best = Math.max(cur, Math.min(left, right))
        out.print((if (best < 0) -1 else (len[i] - best) / 2).toString() + " ")
    }
}

fun scanInt(): Int {
    return scanString().toInt()
}

fun scanLong(): Long {
    return scanString().toLong()
}

fun scanString(): String {
    var t = tok
    while (t == null || !t.hasMoreTokens()) {
        t = StringTokenizer(inp.readLine())
        tok = t
    }
    return t.nextToken()
}

val inp = BufferedReader(InputStreamReader(System.`in`))
val out = PrintWriter(System.out)
var tok: StringTokenizer? = null

fun main() {
    solve()
    inp.close()
    out.close()
}

class IntList {
    var data = IntArray(3)
    var size = 0
    val isEmpty: Boolean
        get() = size == 0

    fun size(): Int {
        return size
    }

    operator fun get(index: Int): Int {
        if (index < 0 || index >= size) {
            throw IndexOutOfBoundsException()
        }
        return data[index]
    }

    fun clear() {
        size = 0
    }

    operator fun set(index: Int, value: Int) {
        if (index < 0 || index >= size) {
            throw IndexOutOfBoundsException()
        }
        data[index] = value
    }

    fun expand() {
        if (size >= data.size) {
            data = Arrays.copyOf(data, (data.size shl 1) + 1)
        }
    }

    fun insert(index: Int, value: Int) {
        if (index < 0 || index > size) {
            throw IndexOutOfBoundsException()
        }
        expand()
        System.arraycopy(data, index, data, index + 1, size++ - index)
        data[index] = value
    }

    fun delete(index: Int): Int {
        if (index < 0 || index >= size) {
            throw IndexOutOfBoundsException()
        }
        val value = data[index]
        System.arraycopy(data, index + 1, data, index, --size - index)
        return value
    }

    fun push(value: Int) {
        expand()
        data[size++] = value
    }

    fun pop(): Int {
        if (size == 0) {
            throw NoSuchElementException()
        }
        return data[--size]
    }

    fun unshift(value: Int) {
        expand()
        System.arraycopy(data, 0, data, 1, size++)
        data[0] = value
    }

    fun shift(): Int {
        if (size == 0) {
            throw NoSuchElementException()
        }
        val value = data[0]
        System.arraycopy(data, 1, data, 0, --size)
        return value
    }
}