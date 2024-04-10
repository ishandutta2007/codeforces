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

    fun solve() {
        val n = ri()
        var x = ri()
        var y = ri()
        if (x > y) {
            var tmp = x
            x = y
            y = tmp
        }
        var ans = 1e8.toInt()
        for (mid in 1..n) {
            if (mid < x || mid >= y) {
                continue
            }
            ans = Math.min(ans, Math.max(cost(x, mid), cost(y - mid, n - mid)))
        }
        writeln(ans)
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