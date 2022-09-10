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
        var sz = IntArray(n)
        var g = Array<MutableList<Int>>(n, { i -> mutableListOf() })
        for (i in 0..n-2) {
            var (x, y) = readInts()
            x--
            y--
            g[x].add(y)
            g[y].add(x)
            sz[x]++
            sz[y]++
        }

        var mx = 0
        for(i in 0..n-1){
            if (sz[i] == 1)
                mx++
        }

        if (k > mx){
            println("No")
            continue
        }

        if (k == 1){
            println("Yes")
            println(1)
            println(1)
            continue
        }

        var visited = IntArray(n)
        var susidy = IntArray(n)

        for(i in 0..n-1){
            visited[i] = 0
            susidy[i] = 0
        }

        fun Dfs(v: Int){
            visited[v] = 1
            if (k == 0) return

            for(u in g[v]){
                if (visited[u] == 1) continue

                if (susidy[v] == 1) k++
                if (susidy[u] == 1) k++

                susidy[v]++
                susidy[u]++

                if (susidy[u] == 1) k--
                if (susidy[v] == 1) k--

                Dfs(u)
                if (k == 0) return;
            }
        }

        Dfs(0)
        println("Yes")
        var cnt = 0
        for(i in 0..n-1){
            cnt += visited[i]
        }

        println(cnt)
        for(i in 0..n-1){
            if (visited[i] == 1){
                print(i + 1)
                print(" ")
            }
        }

        println()
    }
}