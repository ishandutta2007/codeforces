fun main()
{
    var (n, m, k) = readLine()!!.split(" ").map({it.toInt()})
    
    var dp = IntArray(n){0};
    
    for(i in 0..n - 1)
        dp[i] = 1000000000
        
    dp[k - 1] = 0
    
    for(i in 0..m - 1)
    {
        var (x, y) = readLine()!!.split(" ").map({it.toInt()})
        
        x -= 1
        y -= 1
        
        var c = dp[x]
        dp[x] = dp[y]
        dp[y] = c
        
        if(dp[y] + 1 < dp[x])
            dp[x] = dp[y] + 1
            
        if(dp[x] + 1 < dp[y])
            dp[y] = dp[x] + 1
    }
    
    for(i in 0..n - 1)
    {
        if(dp[i] > m)
            print(-1)
        else print(dp[i])
        
        print(" ")
    }
}