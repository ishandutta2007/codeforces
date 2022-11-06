import java.lang.StringBuilder
import java.util.*
import java.util.function.IntFunction
import java.util.function.Supplier
import kotlin.collections.ArrayList

class A {
    val reader = System.`in`.bufferedReader();
    val writer = StringBuilder(1 shl 14);
    var tokenizer = StringTokenizer("");
    fun read(): String {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    fun ri(): Int {
        return read().toInt();
    }

    fun rl(): Long {
        return read().toLong();
    }

    fun <T> write(x: T): A {
        writer.append(x);
        if (writer.length >= 1 shl 13) {
            flush();
        }
        return this
    }

    fun writeln(): A {
        writer.append('\n');
        return this
    }

    fun <T> writeln(x: T): A {
        write(x);
        writeln();
        return this
    }

    fun flush() {
        System.out.append(writer.toString());
        writer.setLength(0);
    }

    fun solve() {
        var n = ri()
        var a = IntArray(n)
        for (i in 0 until n) {
            a[i] = ri()
        }
        var qNum = ri()
        var qs = Array<Query>(qNum, { i ->
            Query(ri() - 1, ri() - 1, 0)
        });
        var sortQs = qs.clone()
        sortQs.sortBy { x -> x.r }
        var head = 0
        var st = SegmentBeat(0, n - 1)
        for (i in 0 until n) {
            st.updateMin(0, i, 0, n - 1, -a[i].toLong())
            while(head < qNum && sortQs[head].r == i){
                var q = sortQs[head]
                sortQs[head].ans = -st.querySum(q.l, q.r, 0, n - 1)
                head++
            }
        }
        for(q in qs){
            write(q.ans).write(' ')
        }
    }
}

class Query(var l: Int, var r: Int, var ans: Long) {

}

interface IntToLongFunction {
    fun apply(x: Int): Long
}

internal class SegmentBeat(l: Int, r: Int) : Cloneable {
    private var left: SegmentBeat? = null
    private var right: SegmentBeat? = null
    private var first: Long = 0
    private var second: Long = 0
    private var firstCnt = 0
    private var sum: Long = 0
    private fun setMin(x: Long) {
        if (first <= x) {
            return
        }
        sum -= (first - x) * firstCnt
        first = x
    }

    fun pushUp() {
        first = Math.max(left!!.first, right!!.first)
        second = Math.max(
            if (left!!.first == first) left!!.second else left!!.first,
            if (right!!.first == first) right!!.second else right!!.first
        )
        firstCnt =
            (if (left!!.first == first) left!!.firstCnt else 0) + if (right!!.first == first) right!!.firstCnt else 0
        sum = left!!.sum + right!!.sum
    }

    fun pushDown() {
        left!!.setMin(first)
        right!!.setMin(first)
    }

    private fun covered(ll: Int, rr: Int, l: Int, r: Int): Boolean {
        return ll <= l && rr >= r
    }

    private fun noIntersection(ll: Int, rr: Int, l: Int, r: Int): Boolean {
        return ll > r || rr < l
    }

    fun updateMin(ll: Int, rr: Int, l: Int, r: Int, x: Long) {
        if (noIntersection(ll, rr, l, r)) {
            return
        }
        if (covered(ll, rr, l, r)) {
            if (first <= x) {
                return
            }
            if (second < x) {
                setMin(x)
                return
            }
        }
        pushDown()
        val m: Int = (l + r) / 2
        left!!.updateMin(ll, rr, l, m, x)
        right!!.updateMin(ll, rr, m + 1, r, x)
        pushUp()
    }

    fun querySum(ll: Int, rr: Int, l: Int, r: Int): Long {
        if (noIntersection(ll, rr, l, r)) {
            return 0
        }
        if (covered(ll, rr, l, r)) {
            return sum
        }
        pushDown()
        val m: Int = (l + r) / 2
        return left!!.querySum(ll, rr, l, m) +
                right!!.querySum(ll, rr, m + 1, r)
    }

    fun queryMax(ll: Int, rr: Int, l: Int, r: Int): Long {
        if (noIntersection(ll, rr, l, r)) {
            return -inf
        }
        if (covered(ll, rr, l, r)) {
            return first
        }
        pushDown()
        val m: Int = (l + r) / 2
        return Math.max(
            left!!.queryMax(ll, rr, l, m),
            right!!.queryMax(ll, rr, m + 1, r)
        )
    }

    private fun deepClone(): SegmentBeat {
        val seg = clone()
        if (seg.left != null) {
            seg.left = seg.left!!.deepClone()
        }
        if (seg.right != null) {
            seg.right = seg.right!!.deepClone()
        }
        return seg
    }

    override fun clone(): SegmentBeat {
        return try {
            super.clone() as SegmentBeat
        } catch (e: CloneNotSupportedException) {
            throw RuntimeException(e)
        }
    }

    private fun toString(builder: StringBuilder) {
        if (left == null && right == null) {
            builder.append(sum).append(",")
            return
        }
        pushDown()
        left!!.toString(builder)
        right!!.toString(builder)
    }

    override fun toString(): String {
        val builder = StringBuilder()
        deepClone().toString(builder)
        if (builder.length > 0) {
            builder.setLength(builder.length - 1)
        }
        return builder.toString()
    }

    companion object {
        private const val inf = 2e18.toLong()
    }

    init {
        if (l < r) {
            val m: Int = (l + r) / 2
            left = SegmentBeat(l, m)
            right = SegmentBeat(m + 1, r)
            pushUp()
        } else {
            first = 0
            sum = first
            second = -inf
            firstCnt = 1
        }
    }
}


fun main(args: Array<String>) {
    val sol = A()
    val t = 1;//sol.ri()
    for (i in 1..t) {
        sol.solve()
    }
    sol.flush()
}