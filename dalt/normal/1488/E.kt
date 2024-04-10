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

    fun cost(x: Int, n: Int): Int {
        return Math.min(
            x - 1 + n - 1,
            n - x + n - 1
        )
    }

    fun check(m: Long, n: Long, s: Long): Boolean {
        var cnt = 0L
        var last = m
        var day = 0L
        while(day < n && cnt <= s && last > 1){
            day++
            cnt += last
            last = (last + 1) / 2
        }
        if(last == 1L){
            cnt += n - day
        }
        return cnt <= s
    }

    fun solve() {
        val n = ri()
        val a = IntArray(n + 1)
        val pts = ArrayList<Pt>(n)
        val reg = IntArray(n + 1)
        Arrays.fill(reg, -1)
        for(i in 1..n){
            a[i] = ri()
            if(reg[a[i]] != -1){
                pts.add(Pt(reg[a[i]], i, 0))
            }else{
                reg[a[i]] = i
            }
        }
        val bit = IntegerGenericBIT(n, 0)
        pts.sortByDescending { x -> x.x }
        for(pt in pts){
            if(pt.x + 1 < pt.y){
                pt.dp = 1
            }
            pt.dp = Math.max(pt.dp, bit.query(pt.y))
            pt.dp += 2
            bit.update(pt.y, pt.dp)
        }
        var ans = 1
        for(pt in pts){
            ans = Math.max(ans, pt.dp)
        }
        writeln(ans)
    }
}

class Pt(var x: Int, var y: Int, var dp:Int) {
}



internal class IntegerGenericBIT(private val n: Int, unit: Int) {
    private val data: IntArray
    private val unit: Int

    /**
     * A[1]+A[2]+...+A[i]
     */
    fun query(i: Int): Int {
        var i = i
        var sum = unit
        while (i > 0) {
            sum = Math.max(sum, data[i])
            i -= i and -i
        }
        return sum
    }

    /**
     * A[i]A[i]+mod
     */
    fun update(i: Int, mod: Int) {
        var i = i
        if (i <= 0) {
            return
        }
        while (i <= n) {
            data[i] = Math.max(data[i], mod)
            i += i and -i
        }
    }

    /**
     * A0
     */
    fun clear() {
        Arrays.fill(data, unit)
    }

    override fun toString(): String {
        val builder = StringBuilder()
        for (i in 1..n) {
            builder.append(query(i)).append(',')
        }
        if (builder.length > 0) {
            builder.setLength(builder.length - 1)
        }
        return builder.toString()
    }

    /**
     * A[1...n]
     */
    init {
        data = IntArray(n + 1)
        this.unit = unit
        clear()
    }
}


fun main(args: Array<String>) {
    val sol = A()
    val t = sol.ri()
    for (i in 1..t) {
        sol.solve()
    }
    sol.flush()
}