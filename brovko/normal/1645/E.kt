fun main()
{
    var (n, k) = readLine()!!.split(" ").map({it.toInt()})
    
    var a = IntArray(35){0}
    
    var x = 0
    var s = 0
    
    while(n > 0)
    {
        a[x] = n % 2
        s += a[x]
        x += 1
        n /= 2
    }
    
    while(x > 0)
    {
        var cnt = 0
        
        if(k - s > 0)
            cnt = k - s
            
        if(a[x] < cnt)
            cnt = a[x]
            
        s += cnt
        a[x] -= cnt
        a[x - 1] += 2 * cnt
        
        x -= 1
    }
    
    if(k != s)
        print("NO")
    else
    {
        println("YES")
        
        var p = 1
        
        for(i in 0..30)
        {
            for(j in 1..a[i])
            {
                print(p)
                print(" ")
            }
                
            p *= 2
        }
    }
}