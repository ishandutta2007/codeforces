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

var reader = InputReader(System.`in`)
var outp = PrintWriter(System.out)

class P(var a: Long, var b: Long, var c: Long){

}

fun main(){
    var n = reader.nextInt()
    var arr = Array(n) {i -> ""}
    var edges = Array(36) {i -> mutableListOf<Int>()}
    var best = "kotlin"
    for (i in 0 until n){
        var s = reader.next()
        for (j in 0 until 6){
            if (s[0] == best[j]){
                var L = j
                var R = (j+s.length)%6
                edges[L*6+R].add(i)
            }
        }
    }
    var st = mutableListOf<Int>()
    var ed = mutableListOf<Int>()
    st.add(0)
    ed.add(-1)
    var res = mutableListOf<Int>()
    while (st.size > 0){
        var w = st.last()
        var was_added = false
        for (j in 0 until 36){
            var L = j/6
            var R = j%6
            if (L!=w) continue
            if (edges[j].size == 0) continue
            var E = edges[j].last()
            edges[j].removeAt(edges[j].size - 1)
            was_added = true
            st.add(R)
            ed.add(E+1)
            break
        }
        if (!was_added){
            st.removeAt(st.size - 1)
            if (ed.last() != -1){
                res.add(ed.last())
            }
            ed.removeAt(ed.size - 1)
        }
    }
    for (i in 0 until n){
        outp.print(res[n-i-1])
        outp.print(" ")
    }
    outp.close()
}