import java.io.File

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(){
    var t = readInt()
    while(t-- > 0){
        var n = readInt()
        var (maxK, minK, kek) = listOf(1000000, 0, 0)
        while(n-- > 0) {
            val (a, b, _c) = readStrings()
            val c = _c.toInt()
            var ans = 0
            var pA = a.length - 1
            var pB = b.length - 1
            while(pA >= 0 && pB >= 0){
                if (a[pA] != b[pB]){
                    break
                }

                pA--
                pB--
                ans++
            }

            if (c == 1){
                maxK = Math.min(maxK, ans)
            }else{
                minK = Math.max(minK, ans + 1)
            }
        }

        if (maxK < minK){
            println(0)
            println()
        }else {
            println(maxK - minK + 1)
            for (i in minK..maxK) {
                print("$i ")
            }
            println()
        }
    }
}