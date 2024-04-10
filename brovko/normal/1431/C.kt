fun main()
{
    var t = readLine()!!.toInt()
    
    for(i in 0..t - 1)
    {
        var b = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
        var n = b[0]
        var k = b[1]
        var a = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
        var ps: Array<Int> = Array(n + 1){0}
        
        for(j in 0..n - 1)
        {
            ps[j + 1] = ps[j] + a[j]
        }
        
        var ans = 0
        
        for(j in n-1 downTo 0)
        {
            var d:Int = (n - j) / k
            var x = ps[j + d] - ps[j]
            
            if(x > ans)
                ans = x
        }
        
        println(ans)
    }
}