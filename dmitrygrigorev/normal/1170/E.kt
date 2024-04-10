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
    var arr = Array<Int>(n) {i -> -1}
    for (i in 0 until n){
        var k = reader.nextInt()
        arr[i] = k
    }
    var pref = Array<Int>(n+1) {i->0}
    for (i in 0 until n){
        pref[i+1] = pref[i] + arr[i]
    }
    var q = reader.nextInt()
    for (i in 0 until q){
        var k = reader.nextInt()
        var start = 0
        var ptr = 0
        for (j in 0 until k+1){
            var nw = m+1
            if (j < k) nw = reader.nextInt()
            var space = nw - start-1
            var L = 0
            var R = n-ptr+1
            while (R-L>1){
                var M = (L+R)/2
                var sm = pref[ptr+M]-pref[ptr]
                if (sm <= space) L = M
                else R = M
            }
            ptr += L
            start = nw
        }
        if (ptr == n) outp.println("YES")
        else outp.println("NO")
    }
    outp.close()
}