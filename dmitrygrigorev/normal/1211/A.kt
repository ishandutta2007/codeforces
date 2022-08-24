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
    for (i in 0 until n){
        var l = -1
        var r = -1
        for (j in 0 until n){
            if (arr[j] < arr[i]) l = j
        }
        for (j in 0 until n){
            if (arr[j] > arr[i]) r = j
        }
        if (l==-1 || r==-1) continue
        outp.print(l+1)
        outp.print(" ")
        outp.print(i+1)
        outp.print(" ")
        outp.print(r+1)
        outp.close()
        exitProcess(0)
    }
    outp.println("-1 -1 -1")
    outp.close()
}