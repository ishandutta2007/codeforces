fun main()
{
    var t = readLine()!!.toInt()
    
    for(ggwefrggf in 0..t - 1)
    {
        var n = readLine()!!.toInt()
        var s = readLine()!!
        var a = readLine()!!
        
        a += "000"
        
        var ans = 0
        
        for(i in 0..n - 4)
        {
            if(a[i] == '1')
            {
                if((a[i + 1] == '1') or (a[i + 3] == '1'))
                    ans = -1000000000
                    
                else if(a[i + 2] == '1')
                {
                    if(s[i] == ')')
                        ans += 1
                        
                    if(s[i + 1] == '(')
                        ans += 1
                }
                
                else
                {
                    var x = 0
                    
                    if(s[i] == ')')
                        x += 1
                        
                    if(s[i + 1] == '(')
                        x += 1
                        
                    if(s[i + 2] == ')')
                        x += 1
                        
                    if(s[i + 3] == '(')
                        x += 1
                        
                    var F = 0
                        
                    if(i >= 2)
                        if(a[i - 2] == '1')
                            F = 1
                            
                    if(F == 0)
                    {
                        var y = x - 2
                            
                        if(s[i + 1] == ')')
                            y += 2
                        
                        if(s[i + 2] == '(')
                            y += 2
                            
                        if(y < x)
                            x = y
                    }
                        
                    ans += x
                }
            }
        }
        
        if(ans < 0)
            println(-1)
        else println(ans)
    }
}