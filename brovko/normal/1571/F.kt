fun main()
{
    var (n, m) = readLine()!!.split(" ").map({it.toInt()})
    
    var k = IntArray(5005){0}
    var t = IntArray(5005){0}
    var used = IntArray(5005){0}
    var T = IntArray(5005){0}
    var dp = Array(5005){IntArray(5005){0}}
    
    for (i in 0..n - 1)
    {
        var (x, y) = readLine()!!.split(" ").map({it.toInt()})
        k[i] = x
        t[i] = y
        
        if(t[i] == 1)
            m -= k[i]
    }
    
    dp[0][0] = 1
    
    for(i in 0..n - 1)
        for(j in 0..m)
        {
            dp[i + 1][j] = dp[i][j]
            
            if((t[i] == 2) and (j >= k[i]) and (dp[i + 1][j] == 0))
                dp[i + 1][j] = dp[i][j - k[i]]
        }
        
    var s = 0
    
    for(i in 0..n - 1)
        if(t[i] == 2)
            s += k[i]
            
    var ans = -1

    for(i in 0..m)
        if((dp[n][i] == 1) and (i <= m / 2) and (s - i <= m - m / 2))
            ans = i
            
    if(ans == -1)
    {
        print(-1)
    }
    else
    {
        var I = n
        var J = ans

        while(I > 0)
        {
            I -= 1

            if(dp[I][J] == 0)
            {
                used[I] = 1
                J -= k[I]
            }
        }
        
        var x = 2
        var y = 1

        for(i in 0..n - 1)
            if(t[i] == 2)
            {
                if(used[i] == 1)
                {
                    T[i] = x
                    x += 2 * k[i]
                }
                else
                {
                    T[i] = y
                    y += 2 * k[i]
                }
            }
            
        for(i in 0..n - 1)
            if(t[i] == 1)
            {
                T[i] = m + 1
                m += k[i]
            }

        for(i in 0..n - 1)
        {
            print(T[i])
            print(' ')
        }
    }
}