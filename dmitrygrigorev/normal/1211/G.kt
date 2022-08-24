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

var data = mutableListOf<MutableList<Int>>()
var start = mutableListOf<Int>()
var finish = mutableListOf<Int>()
var bad_positions = mutableListOf<Boolean>()
var was_bad = false
var longest = -1
fun dfs(vertex: Int, last: Int, d:Int) : Pair<Int, Int> {
    var res = Pair(-1, -1)
    if (bad_positions[vertex]) res = Pair(d, vertex)
    for (i in 0 until data[vertex].size){
        var to = data[vertex][i]
        if (to==last) continue
        var tam = dfs(to, vertex, d+1)
        if (tam.first > res.first) res = tam
    }
    return res
}

fun dfs2(vertex:Int, last :Int) : Boolean{
    if (bad_positions[vertex]){
        longest=vertex
    }
    var how = 0
    for (i in 0 until data[vertex].size){
        var to = data[vertex][i]
        if (to==last) continue
        var res = dfs2(to, vertex)
        if (res) how += 1
    }
    if (how >= 2){
        was_bad = true
    }
    if (bad_positions[vertex]) how += 1
    return (how > 0)
}

var path = mutableListOf<Int>()

fun dfs3(vertex:Int, last:Int, target:Int){
    path.add(vertex)
    if (vertex == target){
        var good = true
        for (i in 0 until path.size){
            if (start[path[i]] != finish[path[(i-1+path.size)%path.size]]) good = false
        }
        if (good){
            outp.println("Yes")
            outp.println(path.size)
            for (i in 0 until path.size){
                outp.print(path[i]+1)
                outp.print(" ")
            }
            outp.println()
            was_bad = true
        }
    }
    for (i in 0 until data[vertex].size){
        var to = data[vertex][i]
        if (to==last) continue
        dfs3(to, vertex, target)
    }
    path.removeAt(path.size-1)
}

fun try_to_go(a: Int, b: Int){
    dfs3(a, -1, b)
}

fun solve(){
    data.clear()
    start.clear()
    finish.clear()
    bad_positions.clear()
    var n = reader.nextInt()
    for (i in 0 until n){
        var x = reader.nextInt()
        start.add(x)
        data.add(mutableListOf<Int>())
    }
    for (i in 0 until n){
        var x = reader.nextInt()
        finish.add(x)
    }
    for (i in 0 until n){
        if (start[i] != finish[i]) bad_positions.add(true)
        else bad_positions.add(false)
    }
    for (i in 0 until n-1){
        var u = reader.nextInt()
        var v = reader.nextInt()
        u-=1
        v-=1
        data[u].add(v)
        data[v].add(u)
    }
    var res = dfs(0, -1, 0)
    if (res.first == -1){
        outp.println("Yes")
        outp.println("0")
        return
    }
    was_bad = false
    longest = -1
    var tam = dfs2(res.second, -1)
    if (was_bad){
        outp.println("No")
        return
    }
    var a = res.second
    var b = longest
    if (a==b){
        outp.println("No")
        return
    }
    was_bad = false
    try_to_go(a, b)
    if (!was_bad){
        try_to_go(b, a)
    }
    if (!was_bad){
        outp.println("No")
    }
}

fun main(){
    var t = reader.nextInt()
    for (i in 0 until t){
        solve()
    }
    outp.close()
}