import java.util.PriorityQueue
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
        var N = 1000000000
        var (n, m) = readInts()
        var a = IntArray(n)
        var b = IntArray(n)
        var ans = IntArray(n)

        for(i in 0..n-1){
            var (u, v) = readInts()
            a[i] = u
            b[i] = v
        }

        var idx = LongArray(n)
        for(i in 0..n-1)
            idx[i] = a[i].toLong() * N + i

        idx = idx.sortedArray()

        val pq: PriorityQueue<Long> = PriorityQueue<Long>()

        var res = 0

        var last = -1

        for(id in 0..n){
            var chas = N + N
            if (id < n)
                chas = (idx[id] / N).toInt()

            var kilk = (chas - last).toLong() * m

            var lol = 0
            while(kilk > 0 && !pq.isEmpty()){
                var top = pq.peek()
                pq.remove()

                var ind = (top % N).toInt()
                ans[ind] = last
                if (last > b[ind]){
                    if (res < last - b[ind]){
                        res = last - b[ind];
                    }
                }

                lol++
                if (lol == m){
                    lol = 0
                    last++
                }
                kilk--
            }

            if (id == n) break

            last = chas
            var hto = (idx[id] % N).toInt()
            pq.add(b[hto].toLong() * N + hto)
        }

        println(res)
        for(i in 0..n-1){
            print(ans[i])
            print(" ")
        }

        println()
    }
}