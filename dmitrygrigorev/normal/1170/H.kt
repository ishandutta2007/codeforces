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
    var t = reader.nextInt()
    for (it in 0 until t){
        var n = reader.nextInt()
        var arr = Array<Int>(n) {i -> -1}
        for (i in 0 until n){
            var x = reader.nextInt()
            arr[i] = x
        }
        arr.sort()
        var mx = 0
        var element  = -1
        var start = 0
        while (start < n){
            var finish = start
            while ((finish < n) && (arr[finish] == arr[start])){
                finish++
            }
            if (finish - start >= mx){
                mx = finish - start
                element = arr[start]
            }
            start = finish
        }
        var tot = n
        while (true){
            if (2*mx <= tot) break
            if ((2*mx - 1 ==tot) && ((element == arr[0]) || (element == arr[n-1]))){
                break
            }
            mx--
            tot--
        }
        var rl = mutableListOf<Int>()
        start = 0
        while (start < n){
            var finish = start
            while ((finish < n) && (arr[finish] == arr[start])){
                finish++
            }
            if (arr[start] != element){
                for (j in start until finish){
                    rl.add(arr[j])
                }
                start = finish
                continue
            }
            for (j in 0 until mx){
                rl.add(arr[start+j])
            }
            start = finish
        }
        outp.println(rl.size)
        var nw = mutableListOf<Int>()
        n = rl.size
        for (i in 0 until n/2){
            nw.add(rl[i])
            nw.add(rl[i+(n+1)/2])
        }
        if (n % 2 != 0){
            nw.add(rl[n/2])
        }
        var can = true
        for (i in 0 until n-1){
            if (nw[i] == nw[i+1]) can = false
        }
        if (!can){
            nw = mutableListOf<Int>()
            for (i in 0 until n/2) {
                nw.add(rl[i+n/2])
                nw.add(rl[i])
            }
            if (n % 2 != 0){
                nw.add(rl[n-1])
            }
        }
        for (i in 0 until n){
            outp.print(nw[i])
            outp.print(" ")
        }
        outp.println()
    }
    outp.close()
}