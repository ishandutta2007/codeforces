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
    var a = reader.next().toInt()
    var b = reader.next().toInt()
    var k = reader.next().toInt()

    var r = Array(n) { 0 }

    var was = Array(1000001) { 0 }

    for (i in 0 until n){
        r[i] = reader.next().toInt()
        was[r[i]] += 1
    }

    var ans = 0


    for (v in 1 until 1000001){
        if (v % k == 0) continue
        var cnt = mutableListOf<Int>()

        var value = v
        while(true){
            if (value > 1000000) break
            cnt.add(was[value])
            value *= k
        }

        var last_dp = mutableListOf<Int>(0)

        for (i in 0 until cnt.size){
            var new_dp = mutableListOf<Int>()
            for (j in 0 until cnt[i] + 1) new_dp.add(0)

            for (j in last_dp.size - 2 downTo 0){
                last_dp[j] = max(last_dp[j], last_dp[j + 1])
            }

            for (new_cnt in 0 until cnt[i] + 1){
                if (new_cnt.toLong() * b.toLong() > cnt[i]) break
                if (new_cnt.toLong() * a.toLong() > last_dp.size - 1) break
                new_dp[cnt[i] - new_cnt * b] = last_dp[new_cnt * a] + new_cnt
            }

            last_dp = new_dp
        }

        var ma = 0

        for (x in last_dp) ma = max(ma, x)

        ans += ma
    }


    outp.print(ans)
    outp.close()
}