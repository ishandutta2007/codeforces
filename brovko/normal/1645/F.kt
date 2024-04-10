fun main()
{
    var n = readLine()!!.toInt()
    
    var a = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
    
    var used = IntArray(150005){0}
    used[0] = 1
    
    a.sort()
    var ans = 0
    
    for(i in 0..n - 1)
    {
        var x = a[i] - 1
        
        while((x <= a[i] + 1) and (used[x] == 1))
            x += 1
            
        if(x <= a[i] + 1)
        {
            used[x] = 1
            ans += 1
        }
    }
    
    print(ans)
}