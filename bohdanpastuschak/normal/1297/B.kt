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
    var N = 2007
    while(t-- > 0)
    {
        var n = readInt()
        var a = IntArray(N)
        var b = IntArray(N)
        for(i in 0..n-1){
            var (u, v) = readInts()
            a[i] = u
            b[i] = v
        }

        var ans = -1

        for(i in 0..n-1){
            var arr = IntArray(6)
            arr[0] = a[i] - 1
            arr[1] = a[i]
            arr[2] = a[i] + 1
            arr[3] = b[i] - 1
            arr[4] = b[i]
            arr[5] = b[i] + 1

            for(id in 0..5) {
                var cnt = 0
                for (j in 0..n - 1) {
                    if (a[j] <= arr[id] && arr[id] <= b[j])
                        cnt++
                }

                if (cnt == 1) ans = arr[id]
            }
        }

        println(ans)
    }
}