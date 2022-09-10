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
    while(t-- > 0) {
        var (n, k) = readInts()
        var a = readInts()
        var b = LongArray(n)
        var N = 1000000000L

        for(i in 0..n-1){
            b[i] = a[i].toLong() * N + i;
        }

        b = b.sortedArray()

        var l = -1
        var r = k
        while(r - l > 1){
            var m = (l + r) / 2

            var she = k - m
            var last = (b[n - 1] / N).toInt() + m
            for(i in n - 2 downTo 0){
                var mx = last - (b[i] / N).toInt() - 1
                if (mx > she) mx = she
                she -= mx
                last = (b[i] / N).toInt() + mx
            }

            if (she == 0) r = m;
            else l = m;
        }

        var ans = IntArray(n)
        var she = k - r
        var last = (b[n - 1] / N).toInt() + r
        ans[(b[n - 1] % N).toInt()] = r

        for(i in n - 2 downTo 0){
            var mx = last - (b[i] / N).toInt() - 1
            if (mx > she) mx = she
            she -= mx
            last = (b[i] / N).toInt() + mx
            ans[(b[i] % N).toInt()] = mx
        }

        for(i in 0..n-1){
            print(ans[i])
            print(" ")
        }

        println()
    }
}