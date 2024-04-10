private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var t = readInt()
    while(t-- > 0)
    {
        var n = readInt()
        var a = readInts()

        var bezDod = 0
        var mn = 100000

        for(i in 0..n - 1){
            if (a[i] > 0){
                bezDod += a[i]
                if (mn > a[i]) mn = a[i]
            }
        }

        bezDod -= mn


        var zVid = 0
        var mx = -1000000000

        for(i in 0..n - 1){
            if (a[i] > 0) {
                zVid += a[i]
            }
            if (a[i] < 0){
                if (mx < a[i]) mx = a[i]
            }
        }

        zVid += mx

        if (bezDod >= zVid){
            println(bezDod)
            var was = 0
            for(i in 0..n-1){
                if (a[i] > 0){
                    if (a[i] == mn && was == 0){
                        was = 1
                        print(0)
                    }
                    else{
                        print(1)
                    }
                }
                else{
                    print(0)
                }
            }
        }
        else{
            println(zVid)
            var was = 0
            for(i in 0..n-1){
                if (a[i] >= 0){
                  print(1)
                }
                else{
                    if (a[i] == mx && was == 0){
                        was = 1
                        print(1)
                    }
                    else{
                        print(0)
                    }
                }
            }
        }

        println()
    }
}