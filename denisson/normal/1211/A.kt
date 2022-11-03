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
    var a = Array(n) { 0 }

    for (i in 0 until n){
        a[i] = reader.next().toInt()
    }

    var ma = -1
    var mi = 1000000009
    var pos_ma = -1
    var pos_mi = -1

    for (i in 0 until n){
        if (a[i] > ma){
            ma = a[i]
            pos_ma = i;
        }
        if (a[i] < mi){
            mi = a[i]
            pos_mi = i;
        }
    }

    if (ma == mi){
        outp.print("-1 -1 -1")
        outp.close()
        exit(0)
    }

    for (i in 0 until n){
        if (a[i] != mi && a[i] != ma){
            outp.print(pos_mi + 1)
            outp.print(' ')
            outp.print(i + 1)
            outp.print(' ')
            outp.print(pos_ma + 1)
            outp.close()
            exit(0)
        }
    }

    outp.print("-1 -1 -1")
    outp.close()
}