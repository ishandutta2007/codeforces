fun main()
{
    var t = readLine()!!.toInt()
    
    for(i in 0..t - 1)
    {
        var n = readLine()!!.toInt()
        var a = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
        
        for(j in 0..n - 1)
            a[j] = a[j] * 1000 + j
            
        a.sort()
        
        var L = 0
        var R = n - 2
        
        print(a[n - 1] % 1000 + 1)
        print(" ")
        
        while(L <= R)
        {
            R -= a[L] / 1000 - 1
            L += 1
            
            for(j in R + a[L - 1] / 1000 - 1 downTo R + 1)
                if(L - 1 < j)
                {
                    print(a[j] % 1000 + 1)
                    print(" ")
                }
            
            
            print(a[L - 1] % 1000 + 1)
            print(" ")
            
        }
        println()
    }
}