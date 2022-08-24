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
    val n = reader.nextInt()
    val m = reader.nextInt()
    val k = reader.nextInt()
    val arr = Array<Int>(n) {i -> -1}
    for (i in 0 until n){
        val v = reader.nextInt()
        arr[i] = v
    }
    if (m == 1){
        print(0)
        exitProcess(0)
    }
    arr.sort()
    var ans = (1e18).toLong()
    val pref = Array<Long>(n+1) {i->0}
    for (i in 0 until n){
        pref[i+1] = pref[i] + (arr[i]).toLong()
    }
    val K = k.toLong()
    for (i in 0 until n-m/2){
        var L = 1
        var R = kotlin.math.min(i+1, (m+1)/2) + 1
        var ss = 0L
        while (R-L > 1){
            var M = (L+R)/2
            var sum = pref[i+1] - pref[i-M+1]
            sum = arr[i].toLong() * M.toLong() - sum
            if (sum <= K){
                L = M
                ss = sum
            }
            else R = M
        }
        if (L == (m+1)/2){
            var tet = pref[i+m/2+1] - pref[i+1]
            tet -= (m/2).toLong() * (arr[i+1]).toLong()
            tet += (m/2).toLong() * (arr[i+1] - arr[i]).toLong()
            ans = kotlin.math.min(ans, tet+ss)
        }
        else{
            var need = m - L
            if (need >= n-i) continue
            var tet = pref[i+need+1] - pref[i+1]
            tet -= (need).toLong() * (arr[i+1]).toLong()
            tet += (need).toLong() * (arr[i+1] - arr[i]).toLong()
            tet += ss
            var mv = kotlin.math.min((arr[i+1]-arr[i]-1).toLong(), (K-ss)/L)
            var good = (need - L)
            tet -= good.toLong() * mv.toLong()
            ans = kotlin.math.min(ans, tet)
        }
    }
    print(ans)
}