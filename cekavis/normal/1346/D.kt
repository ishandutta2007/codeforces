import kotlin.math.max
import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var t = readInt()
    while(t-->0){
        val (n, m) = readInts()
        val a = Array(n) { 0 }
        val u = Array(m) { 0 }
        val v = Array(m) { 0 }
        val w = Array(m) { 0 }
        for (i in 0 until m){
            var (uu, vv, ww) = readInts()
            --uu
            --vv
            a[uu]=max(a[uu], ww)
            a[vv]=max(a[vv], ww)
            u[i]=uu
            v[i]=vv
            w[i]=ww
        }
        var o = true
        for (i in 0 until m){
            o= o && min(a[u[i]], a[v[i]])==w[i]
        }
        if(o){
            println("YES")
            for (i in 0 until n) print("${a[i]}${if (i==n-1) '\n' else ' '}")
        }
        else println("NO")
    }
}