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
        var n = readInt()
        var a = readInts()

        var A = 0
        var B = 0

        var last = 0
        var l = 0
        var r = n - 1
        var sum = 0
        for(i in 0..n-1){
            sum += a[i]
        }

        var player = 0
        var ans = 0
        while(sum > last){
            ans++
            var curr = 0
            if (player == 0){
                while(curr <= last){
                    curr += a[l]
                    l++
                }

                A += curr
            }else{
                while(curr <= last){
                    curr += a[r];
                    r--;
                }

                B += curr
            }

            player = 1 - player;
            last = curr
            sum -= last
        }

        if (sum > 0){
            ans++
            if (player == 0){
                A += sum
            }else{
                B += sum
            }
        }

        print(ans)
        print(' ')
        print(A)
        print(' ')
        print(B)
        println(' ')
    }
}