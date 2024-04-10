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
    var s = reader.next()
    var best_cnt = -1
    var ans = ""
    for (c1 in 'A'..'Z'){
        for (c2 in 'A'..'Z'){
            var new_cnt = 0
            for (i in 0 until s.length - 1){
                if (s[i] == c1 && s[i + 1] == c2){
                    new_cnt += 1;
                }
            }
            if (new_cnt > best_cnt){
                best_cnt = new_cnt
                ans = c1.toString() + c2
            }
        }
    }

    outp.print(ans)

    outp.close()
}