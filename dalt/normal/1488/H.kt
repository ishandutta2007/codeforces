import java.lang.StringBuilder
import java.util.*
import java.util.function.Consumer
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
        val n: Int = ri()
        val q: Int = ri()
        val a = IntArray(n - 1)
        for(i in 0 until n - 1){
            a[i] = ri()
        }
        val st: SegTree<SumImpl, UpdateImpl> = SegTree<SumImpl, UpdateImpl>(0, n - 2, { SumImpl() }, { UpdateImpl() }) { i ->
            val ans = SumImpl()
            ans.end = a[i]
            ans.start = ans.end
            for (j in 0..3) {
                ans.state[j][j] = 1
            }
            ans
        }
        val mod = 998244353
        for (i in 0 until q) {
            val x: Int = ri() - 1
            a[x] = a[x] xor 1
            val upd = UpdateImpl()
            upd.x = a[x]
            st.update(x, x, 0, n - 2, upd)
            val whole = st.sum
            var ans: Long = 0
            if (whole!!.end == 0) {
                for (j in 0..3) {
                    for (k in 0..3) {
                        ans += whole!!.state[j][k] * (k + 1)
                    }
                }
            } else {
                for (j in 0..3) {
                    for (k in 0..3) {
                        ans += whole!!.state[j][k] * (3 - k)
                    }
                }
            }
            ans %= mod.toLong()
            writeln(ans)
        }
    }
}


internal interface Update<U : Update<U>> : Cloneable {
    fun update(u: U)
    fun clear()
    fun ofBoolean(): Boolean
}

internal interface Sum<S, U> : Cloneable {
    fun add(s: S)
    fun update(u: U)
    fun copy(s: S)
}


class UpdateImpl : Update<UpdateImpl> {
    var x = 0

    override fun update(update: UpdateImpl) {
        x = update.x
    }

    override fun clear() {
        x = -1
    }

    override fun ofBoolean(): Boolean {
        return x != -1
    }

}

internal class SumImpl : Sum<SumImpl, UpdateImpl> {
    var state = Array(4) { LongArray(4) }
    var start = 0
    var end = 0
    override fun add(sum: SumImpl) {
        for (i in 0..3) {
            for (j in 0..3) {
                buf[i][j] = state[i][j]
                state[i][j] = 0
            }
        }
        if (end == 1) {
            for (i in 0..3) {
                for (j in 1..3) {
                    buf[i][j] += buf[i][j - 1]
                    if (buf[i][j] >= mod) {
                        buf[i][j] = buf[i][j] - mod
                    }
                }
            }
            if (sum.start == 1) {
                for (i in 0..3) {
                    for (j in 0..3) {
                        for (k in 0..3) {
                            state[i][k] += buf[i][j] * sum.state[j][k] % mod
                        }
                    }
                }
            } else {
                for (i in 0..3) {
                    for (j in 1..3) {
                        for (k in 0..3) {
                            state[i][k] += buf[i][j - 1] * sum.state[j][k] % mod
                        }
                    }
                }
            }
        } else {
            for (i in 0..3) {
                for (j in 2 downTo 0) {
                    buf[i][j] += buf[i][j + 1]
                    if (buf[i][j] >= mod) {
                        buf[i][j] = buf[i][j] - mod
                    }
                }
            }
            if (sum.start == 0) {
                for (i in 0..3) {
                    for (j in 0..3) {
                        for (k in 0..3) {
                            state[i][k] += buf[i][j] * sum.state[j][k] % mod
                        }
                    }
                }
            } else {
                for (i in 0..3) {
                    for (j in 0..2) {
                        for (k in 0..3) {
                            state[i][k] += buf[i][j + 1] * sum.state[j][k] % mod
                        }
                    }
                }
            }
        }
        for (i in 0..3) {
            for (j in 0..3) {
                state[i][j] = state[i][j] % mod
            }
        }
        end = sum.end
    }

    override fun update(update: UpdateImpl) {
        end = update.x
        start = end
    }

    override fun copy(sum: SumImpl) {
        start = sum.start
        end = sum.end
        for (i in 0..3) {
            for (j in 0..3) {
                state[i][j] = sum.state[i][j]
            }
        }
    }

    override fun clone(): SumImpl {
        val ans = SumImpl()
        ans.copy(this)
        return ans
    }

    companion object {
        var mod = 998244353
        var buf = Array(4) { LongArray(4) }
    }
}


internal class SegTree<S : Sum<S, U>, U : Update<U>>(
    l: Int, r: Int, sSupplier: Supplier<S>, uSupplier: Supplier<U>,
    func: IntFunction<S>
) : Cloneable {
    private var left: SegTree<S, U>? = null
    private var right: SegTree<S, U>? = null
    var sum: S? = null
    private var update: U
    private fun modify(x: U) {
        update!!.update(x)
        sum!!.update(x)
    }

    private fun pushDown() {
        if (update!!.ofBoolean()) {
            left!!.modify(update)
            right!!.modify(update)
            update!!.clear()
            assert(!update!!.ofBoolean())
        }
    }

    private fun pushUp() {
        sum!!.copy(left!!.sum!!)
        sum!!.add(right!!.sum!!)
    }

    private fun cover(L: Int, R: Int, l: Int, r: Int): Boolean {
        return L <= l && R >= r
    }

    private fun leave(L: Int, R: Int, l: Int, r: Int): Boolean {
        return R < l || L > r
    }

    fun update(L: Int, R: Int, l: Int, r: Int, u: U) {
        if (leave(L, R, l, r)) {
            return
        }
        if (cover(L, R, l, r)) {
            modify(u)
            return
        }
        val m: Int = (l + r) / 2
        pushDown()
        left!!.update(L, R, l, m, u)
        right!!.update(L, R, m + 1, r, u)
        pushUp()
    }


    init {
        update = uSupplier.get()
        update!!.clear()
        if (l < r) {
            sum = sSupplier.get()
            val m: Int = (l + r) / 2
            left = SegTree(l, m, sSupplier, uSupplier, func)
            right = SegTree(m + 1, r, sSupplier, uSupplier, func)
            pushUp()
        } else {
            sum = func.apply(l)
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