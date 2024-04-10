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
import java.util.concurrent.atomic.AtomicReferenceArray

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

var g = Array(100007) { mutableListOf< Int >() }

var ord = mutableListOf<Int>()

fun dfs(v : Int){
    while(g[v].size > 0){
        var now = g[v][g[v].size - 1]
        g[v].removeAt(g[v].size - 1)
        dfs(now)
    }
    ord.add(v)
}

fun main(){
    var n = reader.next().toInt()
    var a = Array<String>(n) { "" }

    for (i in 0 until n){
        a[i] = reader.next()
    }

    var edge = Array(6) { Array(6) { mutableListOf<Int>() } }

    for (i in 0 until n){
        var w1 = -1
        var w2 = -1

        if (a[i][0] == 'k') w1 = 0
        if (a[i][0] == 'o') w1 = 1
        if (a[i][0] == 't') w1 = 2
        if (a[i][0] == 'l') w1 = 3
        if (a[i][0] == 'i') w1 = 4
        if (a[i][0] == 'n') w1 = 5

        if (a[i][a[i].length - 1] == 'k') w2 = 1
        if (a[i][a[i].length - 1] == 'o') w2 = 2
        if (a[i][a[i].length - 1] == 't') w2 = 3
        if (a[i][a[i].length - 1] == 'l') w2 = 4
        if (a[i][a[i].length - 1] == 'i') w2 = 5
        if (a[i][a[i].length - 1] == 'n') w2 = 0

        g[w1].add(w2)

        /*println(a[i])
        print(w1)
        print(' ')
        println(w2)
        println(i)*/

        edge[w1][w2].add(i)
    }

    dfs(0)

    var ans = mutableListOf<Int>()

    ord.reverse()

    for (i in 0 until ord.size - 1){
        var w1 = ord[i]
        var w2 = ord[i + 1]

        ans.add(edge[w1][w2][edge[w1][w2].size - 1])

        edge[w1][w2].removeAt(edge[w1][w2].size - 1)

    }

    for (x in ans) {
        outp.print(x + 1)
        outp.print(' ')
    }
    outp.close()
}