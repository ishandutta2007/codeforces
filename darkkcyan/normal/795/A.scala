object Main extends App {
    val sc = new java.util.Scanner(System.in)
    val n = sc.nextInt()
    val a, b = sc.nextLong()
    val s = sc.next()
    var cnt = 0
    for (i <- 0 to n - 1) {
        if (s.charAt(i) == '1') cnt = cnt + 1
    }
    
    var ans = 1e18.toLong
    for (i <- 1 to cnt) {
        var t1 = (n / i).toLong
        var t2 = (n % i).toLong
        // println(t1 + " " + t2)
        var x1 = (a + b * (t1 - 1) * (t1 - 1)) * (i - t2)
        var x2 = (a + b * t1 * t1) * t2
        if (ans > x1 + x2) ans = x1 + x2
    }
    print(ans)
}