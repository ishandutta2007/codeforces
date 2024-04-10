import kotlin.math.max
import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val (n, m, k)=readInts()
    val a=Array(n) { m+1 }
    a[k-1]=0
    repeat(m){
        val (x, y)=readInts().map { i -> i-1 }
        val xx= min(a[x]+1, a[y])
        val yy= min(a[y]+1, a[x])
        a[x]=xx
        a[y]=yy
    }
    for (i in 0 until n) print("${if (a[i]>m) -1 else a[i]}${if (i==n-1) '\n' else ' '}")
}