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

fun main(){
    var n = reader.next().toInt()
    var k = reader.next().toInt()

    val a = Array(n) { 0 }

    for (i in 0 until n){
        a[i] = reader.next().toInt()
    }


    a.sort()
    
    if (k == 0){
        if (a[0] == 1){
            outp.print(-1)
            outp.close()
            exit(0)
        }
        outp.print(a[0] - 1)
        outp.close()
        exit(0)
    }

    if (k == n){
        print(a[n - 1])
        outp.close()
        exit(0)
    }

    if (a[k] == a[k - 1]){
        outp.print(-1)
        outp.close()
        exit(0)
    }

    outp.print(a[k - 1])
    outp.close()
}