import kotlin.reflect.jvm.internal.impl.protobuf.LazyStringArrayList

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
//Fast IO: https://github.com/finalchild/kotlin-fast-io/blob/master/src/solution.kt#L97

fun main(){
    var tc = readInt()
    while(tc-- > 0) {

        var (n, m) = readInts()
        var a = mutableListOf<Long>()
        for(i in 0..n-1){
            var s = readLn()
            var lol = 3000000000
            lol = 0
            for(j in 0..m-1){
                lol += lol
                if (s[j] == '1'){
                    lol++
                }
            }
            a.add(lol)
        }

        fun check(cand: Long): Long{
            var less = cand

            for(i in 0..n-1){
                if (a[i] < cand){
                    less--
                }
            }

            return less
        }

        fun je(cand: Long): Int{

            for(i in 0..n-1){
                if (a[i] == cand){
                    return 1
                }
            }

            return 0
        }

        var AAA = 3000000000
        AAA = 1
        for(i in 0..m-1) {
            AAA += AAA;
        }

        var all = AAA - n
        var needLess = (all - 1) / 2

        var curr = AAA / 2 - 1

        var magic = 257
        for(i in curr-magic .. curr+magic){
            if (check(i) == needLess && je(i) == 0){
                curr = i
                break
            }
        }

        var result = CharArray(m)

        var HUJ = 3000000000
        HUJ = 0
        for(iter in 1..m){
            if ((curr % 2) == HUJ){
                result[m - iter] = '0'
            }else{
                result[m - iter] = '1'
            }

            curr /= 2
        }

        for(i in 0..m-1){
            print(result[i])
        }
        println("")
    }
}