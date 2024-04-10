fun main()
{
    var t = readLine()!!.toInt()
    
    for(isdv in 0..t - 1)
    {
        var (n, k, x, y) = readLine()!!.split(" ").map({it.toLong()})
        var a = readLine()!!.split(" ").map({it.toLong()}).toMutableList()
        
        a.sort()
        
        var ans = 0L
        
        for(i in a)
            if(i > k)
                ans += x
                
        var s = 0L
        
        for(i in a)
            s += i
            
        var cnt = 0L
        
        if((s <= k * n) and (cnt * x + y < ans))
            ans = cnt * x + y
            
        for(i in 0..n - 2)
        {
            s -= a[(n - 1 - i).toInt()]
            cnt += 1L
            
            if((s <= k * n) and (cnt * x + y < ans))
                ans = cnt * x + y
        }
            
        println(ans)
    }
}