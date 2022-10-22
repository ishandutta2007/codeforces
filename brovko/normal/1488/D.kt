fun main()
{
    var t = readLine()!!.toInt()
    
    for(i in 0..t - 1)
    {
        var a = readLine()!!.split(" ").map({it.toLong()}).toMutableList()
        
        var n = a[0]
        var s = a[1]
        
        var L = -1L
        var R = 1000000000000000001L
        
        while(R - L > 1)
        {
            var M = (L + R) / 2
            var x = n
            var y = s
            var z = M
            
            while((x >= 1) and (z > 1))
            {
                x -= 1
                y -= z
                z -= z / 2
            }
            
            y -= x
            
            if(y >= 0)
                L = M
            else R = M
        }
        
        println(L)
    }
}