import java.lang.StringBuilder
import java.util.*
import java.util.function.IntFunction
import java.util.function.Supplier

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
        val n = rl()
        var s = rl()

        var lo = 1L
        var hi = 1e18.toLong()
        while (lo < hi) {
            var mid = (lo + hi + 1) / 2
            if(check(mid, n, s)){
                lo = mid
            }else{
                hi = mid - 1
            }
        }

        writeln(lo)
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