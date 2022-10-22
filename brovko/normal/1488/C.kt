fun main()
{
    var t = readLine()!!.toInt()
    
    for(i in 0..t - 1)
    {
        var a = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
        
        var n = a[0]
        var x = a[1]
        var y = a[2]
        
        if(x > y)
        {
            x = a[2]
            y = a[1]
        }
        
        var ans = 1000000000
        var z = 0
        
        for(j in x..y - 1)
        {
            var b = j - 1
            
            if(j - x < x - 1)
                b += j - x
            else b += x - 1
            
            
            var c = n - j - 1
            
            if(n - y > y - j - 1)
                c += y - j - 1
            else c += n - y
            
            
            if(b > c)
                z = b
            else z = c
            
            
            if(z < ans)
                ans = z
        }
        
        println(ans)
    }
}