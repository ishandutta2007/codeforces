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
    var k = reader.nextInt()
    var arr = mutableListOf<P>()
    for (i in 0 until n){
        var a = reader.nextInt()
        var b = reader.nextInt()
        var c = reader.nextInt()
        arr.add(P(a.toLong(), b.toLong(), c.toLong()))
    }
    var mn = 0.toLong()
    var mx = 0.toLong()
    for (i in 0 until n){
        mn += arr[i].a
        mx += arr[i].b
    }
    if (mn > k.toLong() || mx < k.toLong()){
        outp.println(-1)
        outp.close()
        exitProcess(0)
    }
    arr.sortWith(compareBy(
        {-it.c}
    ))
    var ans = 0.toLong()
    for (i in 0 until n){
        mx -= arr[i].a
        ans += arr[i].a * arr[i].c
        k -= arr[i].a.toInt()
        arr[i].b -= arr[i].a
    }
    for (i in 0 until n){
        mx -= arr[i].b
        if (k.toLong() <= mx){
            continue
        }
        var take = k-mx
        ans += take * arr[i].c
        k -= take.toInt()
    }
    outp.print(ans)
    outp.close()
}