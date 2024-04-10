fun main()
{
    var t = readLine()!!.toInt()
    
    for(i in 0..t - 1)
    {
        var a = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
        var s = readLine()!!.toString()
        var k = 0
        var x = 0
        
        for(j in 0..a[0] - 1)
        {
            if(s[j] == '(')
                x += 1
            else x -= 1
            
            if(x == 0)
                k += 1
        }
        
        if(a[0] / 2 < k + a[1])
            println(a[0] / 2)
        else println(k + a[1])
    }
}