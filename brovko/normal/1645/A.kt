fun main()
{
    var t = readLine()!!.toInt()
    
    for(fdhgfh in 0..t - 1)
    {
        var n = readLine()!!.toInt()
        
        var a = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
        
        var b = IntArray(n){0}
        
        for(i in 0..n - 1)
            b[i] = a[i]
        
        a.sort()
        
        var x = 0
        
        if(a[0] == a[1])
            x = n - 1
            
        for(i in 0..n - 1)
            if(b[i] == a[x])
                println(i + 1)
    }
}