fun main()
{
    var (n, m) = readLine()!!.split(" ").map({it.toInt()})
    
    var f = IntArray(m){0}
    var l = IntArray(m){0}
    var F = IntArray(n + 1){0}
    var L = IntArray(n + 1){0}
    var FL = Array(n + 1){IntArray(n + 1){0}}
    
    for(i in 0..m - 1)
    {
        var (x, y) = readLine()!!.split(" ").map({it.toInt()})
        
        f[i] = x
        l[i] = y
        
        F[f[i]] += 1
        L[l[i]] += 1
        FL[f[i]][l[i]] += 1
    }
    
    for(i in 1..n)
    {
        F[i] = n - F[i]
        L[i] = n - L[i]
    }
    
    for(i in 1..n)
        for(j in 1..n)
            FL[i][j] = F[i] + L[j] - (n - FL[i][j])
            
    var ans = 0
    
    for(i in 1..n)
        for(j in 1..n)
            if(i != j)
            {
                var x = 0
            
                if((f[0] != i) and (l[0] != j))
                    x = n - FL[i][j] + 1
                else if((f[0] != i) or (l[0] != j))
                    x - n - F[i] - L[j] + FL[i][j] + 1
                else x = 1
                
                if(x > ans)
                    ans = x
            }
            
    print(ans)
}