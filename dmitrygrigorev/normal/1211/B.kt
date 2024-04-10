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


fun main(){
    var n = reader.nextInt()
    var arr = Array(n) {i -> -1}
    for (i in 0 until n){
        var x = reader.nextInt()
        arr[i] = x
    }
    var ans = 0.toLong()
    for (i in 0 until n){
        var laps = arr[i]-1
        ans = kotlin.math.max(ans, laps.toLong() * n.toLong() + (i+1).toLong())
    }
    outp.print(ans)
    outp.close()
}