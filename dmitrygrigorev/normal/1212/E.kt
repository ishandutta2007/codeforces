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

class P(var size: Int, var profit: Int, var index: Int){

}

fun main(){
    var n = reader.nextInt()
    var arr = mutableListOf<P>()
    for (i in 0 until n){
        var c = reader.nextInt()
        var p = reader.nextInt()
        arr.add(P(c, p, i))
    }
    arr.sortWith(compareBy(
        {-it.profit}, {it.index}
    ))
    var tables = mutableListOf<Pair<Int, Int>>()
    var k = reader.nextInt()
    for (i in 0 until k){
        var x = reader.nextInt()
        tables.add(Pair(x, i))
    }
    tables.sortWith(compareBy(
        {it.first}, {it.second}
    ))
    var ans = 0
    var ans_arr = mutableListOf<Pair<Int, Int>>()
    var used = Array(k) {i->false}
    for (i in 0 until n){
        var was = -1
        for (j in 0 until k){
            if (used[j]) continue
            if (tables[j].first < arr[i].size) continue
            was = j
            break
        }
        if (was == -1) continue
        used[was] = true
        ans += arr[i].profit
        ans_arr.add(Pair(arr[i].index, tables[was].second))
    }
    print(ans_arr.size)
    print(" ")
    println(ans)
    for (i in 0 until ans_arr.size){
        print(ans_arr[i].first+1)
        print(" ")
        println(ans_arr[i].second+1)
    }

}