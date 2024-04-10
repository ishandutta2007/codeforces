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
    var arr = Array<Int>(n) {i -> -1}
    var num = 0
    for (i in 0 until n){
        var t = reader.nextInt()
        arr[i] = t
        if (t==-1) num++
    }
    var tet = Array<MutableList<Int>>(num) {i -> mutableListOf<Int>()}
    var cur = 0
    var prev = mutableListOf<Int>()
    var nxt = mutableListOf<Int>()
    prev.add(-1)
    nxt.add(1)
    for (i in 1 until num+1){
        prev.add(i-1)
        nxt.add(i+1)
    }
    var left = num
    while (left > 0){
        var now = mutableListOf<Int>()
        var start = nxt[0]
        while (start <= num) {
            var ll = nxt[start]
            if (arr[cur] == -1) {
                left--
                var p = prev[start]
                var N = nxt[start]
                if (p >= 0 && p <= num) nxt[p] = N
                if (N >= 0 && N <= num) prev[N] = p
            }
            tet[start-1].add(arr[cur])
            cur++
            start = ll
        }
    }
    outp.println(num)
    for (i in 0 until num){
        outp.print(tet[i].size-1)
        outp.print(" ")
        for (j in 0 until tet[i].size - 1){
            outp.print(tet[i][j])
            outp.print(" ")
        }
        outp.println()
    }
    outp.close()

}