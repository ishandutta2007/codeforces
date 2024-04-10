fun main()
{
    var t = readLine()!!.toInt()
    
    for(i in 0..t - 1)
    {
        var n = readLine()!!.toInt()
        
        var Min = 0
        var Max = 1000000000
        
        for(j in 0..n - 1)
        {
            var (a, b, c) = readLine()!!.split(" ").map({it.toString()}).toMutableList()
            
            var x = a.length - 1
            var y = b.length - 1
            var z = 0
            
            while((x >= 0) and (y >= 0))
            {
                if(a[x] != b[y])
                    break;
                    
                x -= 1
                y -= 1
                z += 1
            }
            
            if(c == "0")
            {
                if(z + 1 > Min)
                    Min = z + 1
            }
            else if(z < Max)
                Max = z
        }
        
        if(Min > Max)
            Min = Max + 1
            
        println(Max - Min + 1)
        
        for(j in Min..Max)
        {
            print(j)
            print(" ")
        }
            
        println()
    }
}