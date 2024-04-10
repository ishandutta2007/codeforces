fun main()
{
    var t = readLine()!!.toInt()
    
    for(odisn in 0..t - 1)
    {
        var (n, m) = readLine()!!.split(" ").map({it.toInt()})
        
        var a = IntArray(n){0}
        var u = IntArray(m){0}
        var v = IntArray(m){0}
        var w = IntArray(m){0}
        
        for(i in 0..m - 1)
        {
            var (x, y, z) = readLine()!!.split(" ").map({it.toInt()})
            
            x -= 1
            y -= 1
            
            u[i] = x
            v[i] = y
            w[i] = z
            
            if(a[x] < z)
                a[x] = z
                
            if(a[y] < z)
                a[y] = z
        }
        
        var F = 1
        
        for(i in 0..m - 1)
            if((a[u[i]] != w[i]) and (a[v[i]] != w[i]))
                F = 0
                
        if(F == 0)
            println("NO")
        else
        {
            println("YES")
            
            for(i in a)
            {
                print(i)
                print(" ")
            }
            
            println()
        }
    }
}