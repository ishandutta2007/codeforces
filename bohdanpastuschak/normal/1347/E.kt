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
    while(tc-- > 0){
        var n = readInt()
        if (n <= 3){
            println(-1)
            continue
        }

        if (n == 4){
            println("3 1 4 2")
            continue
        }

        if (n % 2 == 1){
            for(i in 1..n step 2){
                print(i)
                print(' ')
            }

            print(n - 3)
            print(' ')
            print(n - 1)
            print(' ')

            var i = n - 5
            while(i > 0){
                print(i)
                print(' ')
                i -= 2
            }


            println(' ')
            continue
        }

        for(i in 1..n-1 step 2){
            print(i)
            print(' ')
        }

        print(n - 4)
        print(' ')
        print(n)
        print(' ')
        print(n - 2)
        print(' ')
        var i = n - 6
        while(i > 0){
            print(i)
            print(' ')
            i -= 2
        }

        println(' ')
    }
}