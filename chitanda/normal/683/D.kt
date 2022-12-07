fun main(args: Array<String>) {
    var q = readLine()!!.toInt()
    for(i in 0..q-1){
        var (n, m, p)= readLine()!!.split(' ').map(String::toInt)
        var flag:Int = 0;
        for(j in 1..p)
            if(p % j == 0){
                var k = p / j;
                if(j <= n && k <= m) flag = 1;
            }
        if(flag == 1) println("Yes")
        else println("No")
    }
}