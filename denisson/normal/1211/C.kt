import java.util.*
import kotlin.system.exitProcess
import kotlin.math.*
import java.io.OutputStream
import java.io.IOException
import java.io.InputStream
import java.io.PrintWriter
import java.util.Arrays
import java.util.StringTokenizer
import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.System.exit
import java.lang.System.out
import java.util.EnumSet.range

public class InputReader(stream: InputStream) {
    var reader: BufferedReader
    var tokenizer: StringTokenizer? = null

    init {
        reader = BufferedReader(InputStreamReader(stream), 32768)
        tokenizer = null
    }

    operator fun next(): String {
        while (tokenizer == null || !tokenizer!!.hasMoreTokens()) {
            try {
                tokenizer = StringTokenizer(reader.readLine())
            } catch (e: IOException) {
                throw RuntimeException(e)
            }

        }
        return tokenizer!!.nextToken()
    }

    fun nextInt(): Int {
        return Integer.parseInt(next())
    }

}

var reader = InputReader(System.`in`)
var outp = PrintWriter(System.out)

/*var g = Array(0) { Array(0) { 0 } }
var was = Array(0) { 0 }
var ord = mutableListOf<Int>()

fun dfs(n : Int, v: Int){
    was[v] = 1
    for (to in 0 until n) if (was[to] == 0 && g[v][to] == 1){
        dfs(n, to)
    }
    ord.add(v)
}*/

fun main(){
    var n = reader.next().toInt()
    var k = reader.next().toInt()
    var a = Array(n) { 0 }
    var b = Array(n) { 0 }
    var c = Array(n) { 0 }

    var mi: Long = 0
    var ma: Long = 0

    var ans: Long = 0

    for (i in 0 until n){
        a[i] = reader.next().toInt()
        b[i] = reader.next().toInt()
        c[i] = reader.next().toInt()
        mi += a[i]
        ma += b[i]
    }

    if (mi > k || ma < k){
        outp.print(-1)
        outp.close()
        exit(0)
    }

    var ost: Int = k

    var t = mutableListOf<Pair<Int, Int>>()

    for (i in 0 until n){
        ans += a[i].toLong() * c[i].toLong()
        ost -= a[i]
        t.add(Pair(c[i], b[i] - a[i]))
    }

    t.sortBy { it.first }

    for (i in 0 until t.size){
        var can = min(ost, t[i].second)
        ost -= can
        ans += can.toLong() * t[i].first.toLong()
    }

    outp.print(ans)
    outp.close()
}