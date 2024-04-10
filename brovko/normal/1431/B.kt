fun main()
{
    var t = readLine()!!.toInt()
    
    for(i in 0 .. t - 1)
    {
        var s = readLine()!!.toString()
        var n = s.length
        var ans = 0
        var k = 0
        
        for(j in 0 .. n - 1)
        {
            if(s[j] == 'v')
                k = k + 1
            else
            {
                ans = ans + 1 + k / 2
                k = 0
            }
        }
        
        ans = ans + k / 2
        
        println(ans)
    }
}