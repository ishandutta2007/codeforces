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



    fun solve() {
        val n = ri()
        val k = ri()
        val s = read()
        val right = IntArray(n)
        val size = IntArray(n)
        for(i in n - 1 downTo 0){
            if(s[i] == ')'){
                right[i] = n
                continue
            }
            right[i] = i + 1
            size[i] = 1
            while(right[i] < n && s[right[i]] != ')'){
                size[i] += size[right[i]]
                right[i] = right[right[i]] + 1
            }
        }
        var maxOp = 0
        var now = 0
        var cnt = 0
        while(now < n){
            maxOp += size[now] - 1
            cnt++
            now = right[now] + 1
        }
        writeln(Math.min(k, maxOp) + cnt)
    }
}


fun main(args: Array<String>) {
    val sol = A()
    val t = sol.ri()
    for(i in 1..t) {
        sol.solve()
    }
    sol.flush()
}