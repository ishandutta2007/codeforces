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
        var items = Array<Item>(n + 1, {i -> Item(i, 0)})
        for(i in 1..n){
            for(j in i + i..n step i){
                items[j].cost++
            }
        }
        val pq = TreeSet<Item>()
        for(i in 1..n){
            pq.add(items[i])
        }
        var ans = 0L
        while(!pq.isEmpty()){
            var last = pq.pollLast()
            ans += last.cost
            for(j in 1..n){
                if(j * j > last.id){
                    break
                }
                if(last.id % j != 0){
                    continue
                }
                if(pq.remove(items[j])){
                    items[j].cost--;
                    pq.add(items[j])
                }
                var k = last.id / j
                if(k != j && pq.remove(items[k])){
                    items[k].cost--;
                    pq.add(items[k])
                }
            }
            writeln(ans)
        }
    }
}

class Item(var id: Int, var cost: Int): Comparable<Item>{
    override fun compareTo(other: Item): Int {
        var ans = cost - other.cost;
        if(ans == 0){
            ans = id - other.id;
        }
        return ans
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