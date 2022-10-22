fun main()
{
    var t = readLine()!!.toInt()
    
    for(i in 0..t - 1)
    {
        var n = readLine()!!.toInt()
        var a = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
        var dp = Array<Int>(n + 1){0}
        var tree = Array<Int>(n + 1){0}
        var b = Array<Int>(n + 1){-1}
        
        for(j in 0..n - 1)
        {
            if(b[a[j]] == -1)
                b[a[j]] = j
        }
        
        for(j in n - 1 downTo 0)
        {
            var m = 0
            var r = j
            
            while(r >= 0)
            {
                if(tree[r] > m)
                    m = tree[r]
                    
                r = (r and r + 1) - 1
            }
            
            if(m + 1 > dp[j + 1])
                dp[j + 1] = m + 1
                
                
            m = 0
            r = b[a[j]]
            
            while(r >= 0)
            {
                if(tree[r] > m)
                    m = tree[r]
                    
                r = (r and (r + 1)) - 1
            }
                
            if((b[a[j]] < j) and (dp[b[a[j]] + 1] < m + 2))
            {
                dp[b[a[j]] + 1] = m + 2
                
                var z = b[a[j]] + 1
                
                while(z <= n)
                {
                    if(tree[z] < m + 2)
                        tree[z] = m + 2
                        
                    z = (z or (z + 1))
                }
            }
        }
        
        var ans = 0
        
        for(j in 0..n)
        {
            if(dp[j] > ans)
                ans = dp[j]
        }
        
        println(ans)
    }
}