fun main()
{
    var t = readLine()!!.toInt()
    
    for(ionv in 0..t - 1)
    {
        var (n, k1, k2) = readLine()!!.split(" ").map({it.toInt()})
        var s = readLine()!!
        
        var ans = 0
        
        var a = IntArray(n){0}
        
        for(i in 0..n - 1)
        {
            if(s[i] == '1')
            {
                if(i == 0)
                    a[i] = k1
                else if(k1 < k2 - a[i - 1])
                    a[i] = k1
                else a[i] = k2 - a[i - 1]
                
                ans += a[i]
            }
        }
        
        println(ans)
    }
}