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
    var a = reader.nextInt()
    var b = reader.nextInt()
    var k = reader.nextInt()
    var arr = Array(1000007) {i -> 0}
    for (i in 0 until n){
        var x = reader.nextInt()
        arr[x] += 1
    }
    var ans = 0
    for (i in 1 until 1000007){
        if (i%k == 0) continue
        var tut = mutableListOf<Int>()
        var cur = i
        while (cur < 1000007){
            tut.add(arr[cur])
            cur *= k
        }
        if (a >= b){
            for (j in 0 until tut.size - 1){
                var teams = min(tut[j] / a, tut[j+1] / b)
                ans += teams
                tut[j] -= a*teams
                tut[j+1] -= b*teams
            }
        }
        else{
            for (j in 0 until tut.size - 1){
                var teams = min(tut[tut.size - j - 1] / b, tut[tut.size - j - 2] / a)
                ans += teams
                tut[tut.size - j - 1] -= b*teams
                tut[tut.size - j - 2] -= a*teams
            }
        }
    }
    outp.print(ans)
    outp.close()
}