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

val reader = InputReader(System.`in`)
val outp = PrintWriter(System.out)

fun main(){
    var n = reader.nextInt()
    var m = reader.nextInt()
    var arr = Array<MutableList<Int> >(n) {i -> mutableListOf<Int>()}
    var edges = Array<Pair<Int, Int> >(m) {i-> Pair(-1, -1)}
    for (i in 0 until m){
        var u = reader.nextInt()
        var v = reader.nextInt()
        edges[i] = Pair(u-1, v-1)
        arr[u-1].add(i)
        arr[v-1].add(i)
    }
    var path = mutableListOf<Int>()
    var used = Array<Boolean> (m) {i -> false}
    var vused = Array<Boolean> (n) {i -> false}
    for (i in 0 until n){
        if (arr[i].size % 2 != 0) {
            outp.println("NO")
            outp.close()
            exitProcess(0)
        }
    }
    for (i in 0 until n){
        if (vused[i]) continue
        var kek = mutableListOf<Int>()
        kek.add(i)
        while (kek.size > 0) {
            var w = kek[kek.size - 1]
            var TT = kek.size
            vused[w] = true
            var L = arr[w].size
            for (j in 0 until L) {
                var edge = arr[w][L - j - 1]
                if (used[edge]) {
                    arr[w].removeAt(arr[w].size - 1)
                    continue
                }
                used[edge] = true
                var A = edges[edge].first
                if (A == w) A = edges[edge].second
                kek.add(A)
                arr[w].removeAt(arr[w].size - 1)
                break
            }
            if (kek.size == TT){
                path.add(w)
                kek.removeAt(kek.size - 1)
            }
        }
    }
    outp.println("YES")
    var ans = mutableListOf<MutableList<Int> >()
    var app = Array<Boolean> (n) {i -> false}
    var here = mutableListOf<Int>()
    for (i in 0 until path.size){
        var vertex = path[i]
        if (!app[vertex]){
            app[vertex] = true
            here.add(vertex)
            continue
        }
        var heret = mutableListOf<Int>()
        heret.add(vertex)
        while (here[here.size - 1] != vertex){
            heret.add(here[here.size - 1])
            app[here[here.size - 1]] = false
            here.removeAt(here.size - 1)
        }
        heret.add(vertex)
        ans.add(heret)
    }
    outp.println(ans.size)
    for (i in 0 until ans.size){
        outp.print(ans[i].size)
        outp.print(" ")
        for (j in 0 until ans[i].size){
            outp.print(ans[i][j]+1)
            outp.print(" ")
        }
        outp.println()
    }

    outp.close()
}