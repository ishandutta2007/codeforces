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
    var arr = Array(n) {i -> -1}
    for (i in 0 until n){
        var x = reader.nextInt()
        arr[i] = x
    }
    var L = 0
    var R = n+1
    var ans = mutableListOf<Char>()
    for (i in 0 until n) ans.add('B')
    while (R-L>1){
        var M = (L+R)/2
        var a = mutableListOf<Int>()
        var b = mutableListOf<Int>()
        var x = mutableListOf<Char>()
        var how = Array(M) {i->0}
        for (i in 0 until n){
            if (arr[i] > M){
                x.add('B')
                continue
            }
            how[arr[i] - 1] += 1
            if (a.size == b.size){
                a.add(arr[i])
                x.add('G')
            }
            else if (a.size < b.size){
                if (b[a.size] == arr[i]){
                    a.add(arr[i])
                    x.add('G')
                }
                else{
                    b.add(arr[i])
                    x.add('R')
                }
            }
            else{
                if (a[b.size] == arr[i]){
                    b.add(arr[i])
                    x.add('R')
                }
                else{
                    a.add(arr[i])
                    x.add('G')
                }
            }
        }
        var can = true
        if (a.size != M || b.size != M) can = false
        for (i in 0 until M){
            if (how[i] != 2) can = false
        }
        if (can){
            L = M
            ans = x
        }
        else R = M
    }
    for (i in 0 until n){
        outp.print(ans[i])
    }
    outp.close()
}