fun main()
{
    var (n, m, q) = readLine()!!.split(" ").map({it.toInt()})
    
    var a = Array(n){IntArray(m){0}}
    var s = 0L
    
    var x = LongArray(n){0}
    var y = LongArray(m){0}
    
    for(i in 0..n - 1)
    {
        var ai = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
        
        for(j in 0..m - 1)
        {
            a[i][j] = ai[j]
            s += a[i][j]
            x[i] = x[i] + a[i][j]
            y[j] = y[j] + a[i][j]
        }
    }
    
    for(i in 0..q)
    {
        var mx = 0
        var sx = x[0]
        
        while(sx * 2 < s)
        {
            mx += 1
            sx += x[mx]
        }
        
        var my = 0
        var sy = y[0]
        
        while(sy * 2 < s)
        {
            my += 1
            sy += y[my]
        }
        
        var ans = 0L
        
        for(z in 0..n - 1)
        {
            if(z > mx)
                ans += (z - mx) * x[z]
            else ans += (mx - z) * x[z]
        }
            
        for(z in 0..m - 1)
        {
            if(z > my)
                ans += (z - my) * y[z]
            else ans += (my - z) * y[z]
        }
            
        print(ans)
        print(" ")
        
        if(i < q)
        {
            var (r, c, k) = readLine()!!.split(" ").map({it.toInt()})
            
            r -= 1
            c -= 1
            
            x[r] = x[r] + k - a[r][c]
            y[c] = y[c] + k - a[r][c]
            s += k - a[r][c]
            
            a[r][c] = k
        }
    }
}