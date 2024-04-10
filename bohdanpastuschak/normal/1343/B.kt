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
    var t = readInt()
    while(t-- > 0){
        var n = readInt()
        if (n % 4 == 2){
            println("NO")
            continue
        }

        println("YES")
        var ans = ArrayList<Int>()
        var now = 2
        var it = 0
        while(it < n / 2){
            ans.add(now)
            now += 4
            it++
        }

        it = 0
        now = 3
        while(it < n / 2){
            ans.add(now)
            if (it % 2 == 0){
                now += 2
            }else{
                now += 6
            }
            it++
        }


        println(ans.joinToString(" "))
    }
}