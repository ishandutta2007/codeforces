import java.lang.StringBuilder
import java.util.*
import kotlin.collections.ArrayList

class Main {
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

    fun <T> write(x: T): Main {
        writer.append(x);
        if (writer.length >= 1 shl 13) {
            flush();
        }
        return this
    }

    fun writeln(): Main {
        writer.append('\n');
        return this
    }

    fun <T> writeln(x: T): Main {
        write(x);
        writeln();
        return this
    }

    fun flush() {
        System.out.append(writer.toString());
        writer.setLength(0);
    }

    fun solve() {
        val n = ri();
        val a = IntArray(n, { _ -> ri()});
        val exist = BooleanArray(1000 + 1);
        a.reverse();
        val b = ArrayList<Int>();
        for(x in a){
            if(exist[x]){
                continue;
            }
            exist[x] = true;
            b.add(x);
        }
        writeln(b.size);
        for(x in b.reversed()){
            write(x).write(' ');
        }
    }
}

fun main(args: Array<String>) {
    val sol = Main();
    sol.solve()
    sol.flush();
}