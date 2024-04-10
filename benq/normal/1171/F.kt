fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextInts() = next().split(" ").map { it.toInt() }

fun solve() {
    val n = nextInt()
    var a = ArrayList<ArrayList<Int>>()
    for (i in 0..n-1) {
        val x = ArrayList(nextInts())
        x.add(i); a.add(x)
    }
    
    a.sortBy{ it.get(0) }
    var mx = -1
    
    for (i in 0..n-2) {
        mx = maxOf(mx,a[i][1])
        if (mx < a[i+1][0]) {
            val ans = IntArray(n)
            for (j in 0..i) ans[a[j][2]] = 1
            for (j in i+1..n-1) ans[a[j][2]] = 2
            for (j in 0..n-1) {
                print(ans[j].toString()+' ');
            }
            println()
            return
        }
    }
    println(-1)
}

fun main(args: Array<String>) {
    val t = nextInt()
    for (i in 0..t-1) solve()
}