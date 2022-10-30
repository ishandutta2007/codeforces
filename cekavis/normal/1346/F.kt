import kotlin.math.abs

private fun readLn() = readLine()!! // string line
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

class Line(len: Int){
    val a=Array(len){ 0L }
    fun calc():Long{
        var now=0L
        val sum=a.sum()
        var pos=0
        for (i in a.indices){
            now+=a[i]
            if(now>sum/2){
                pos=i
                break
            }
        }
        var ans=0L
        for (i in a.indices) ans+= abs(i-pos)*a[i]
        return ans
    }
}
fun main() {
    val (n, m, q)=readInts()
    val a=Line(n)
    val b=Line(m)
    val s= mutableListOf<MutableList<Long>>()
    for (i in 0 until n){
        s.add(readInts().map { it.toLong() }.toMutableList())
        for (j in 0 until m){
            a.a[i]+=s[i][j]
            b.a[j]+=s[i][j]
        }
    }
    print("${a.calc()+b.calc()} ")
    repeat(q){
        var (x, y, z)=readInts()
        --x
        --y
        a.a[x]+=z-s[x][y]
        b.a[y]+=z-s[x][y]
        s[x][y]=z.toLong()
        print("${a.calc()+b.calc()}${if (it==q-1) '\n' else ' '}")
    }
}