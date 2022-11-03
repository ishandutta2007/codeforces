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

var a = Array(0) { 0 }
var ans = Array<Char>(0) { 'B' }

fun ok(n : Int, sz : Int) : Boolean {
    var cnt = Array(sz + 1) { 0 }

    for (x in a) if (x <= sz) cnt[x] += 1

    for (i in 1 until sz + 1){
        if (cnt[i] != 2) return false
    }

    var w1 = mutableListOf<Int>()
    var w2 = mutableListOf<Int>()

    var was = mutableSetOf<Int>()

    for (i in 0 until n){
        if (a[i] <= sz){

            if (a[i] in was){
                if (w1.size < w2.size){
                    w1.add(i)
                } else {
                    w2.add(i)
                }
            } else {
                if (w1.size > w2.size){
                    w1.add(i)
                } else {
                    w2.add(i)
                }
            }

            was.add(a[i])
        }
    }

    for (i in 0 until n) ans[i] = 'B'

    for (i in 0 until w1.size){
        ans[w1[i]] = 'R'
        ans[w2[i]] = 'G'
        if (a[w1[i]] != a[w2[i]]) return false
    }

    return true
}

fun main(){
    var n = reader.next().toInt()
    a = Array(n) { 0 }
    ans = Array(n) { 'B' }

    for (i in 0 until n){
        a[i] = reader.next().toInt()
    }

    var vl = 0
    var vr = n + 1

    while(vl + 1 < vr){
        var vm = (vl + vr) / 2
        if (ok(n, vm)) {
            vl = vm
        } else
            vr = vm
    }

    ok(n, vl)

    for (i in 0 until n){
        outp.print(ans[i])
    }
    outp.close()
}