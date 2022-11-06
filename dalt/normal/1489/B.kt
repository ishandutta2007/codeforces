import java.lang.StringBuilder
import java.util.*
import kotlin.math.min

class B {
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

    fun <T> write(x: T): B {
        writer.append(x);
        if (writer.length >= 1 shl 13) {
            flush();
        }
        return this
    }

    fun writeln(): B {
        writer.append('\n');
        return this
    }

    fun <T> writeln(x: T): B {
        write(x);
        writeln();
        return this
    }

    fun flush() {
        System.out.append(writer.toString());
        writer.setLength(0);
    }

    fun solve() {
        val n = rl();
        val a = rl();
        val b = rl();
        val ans = min(n * a, n / 2 * b + n % 2 * a)
        writeln(ans)
    }
}

fun main(args: Array<String>) {
    val sol = B();
    val q = sol.ri();
    for(i in 1..q) {
        sol.solve()
    }
    sol.flush();
}