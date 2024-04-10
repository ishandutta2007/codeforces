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
    for (tests in 0 until t) {
        var (n, m) = readInts()
        
        var out = Array(n, {i -> 0})
        var us = Array(m, {i -> 0})
        var vs = Array(m, {i -> 0})
        var ws = Array(m, {i -> 0})
        
        for (i in 0 until m){
            var (u, v, w) = readInts()
            u -= 1
            v -= 1
            if (w > out[u]){
                out[u] = w
            }
            if (w > out[v]){
                out[v] = w
            }
            
            us[i] = u
            vs[i] = v
            ws[i] = w
        }
        
        var works = true
        
        for (i in 0 until m){
            var u = us[i]
            var v = vs[i]
            var w = ws[i]
            
            if (out[u] != w && out[v] != w){
                works = false
            }
        }
        
        
        if (works){
            println("YES")
            for (v in out){
                print(v)
                print(" ")
            }
            println()
        }
        else {
            println("NO")
        }
        
    }
}