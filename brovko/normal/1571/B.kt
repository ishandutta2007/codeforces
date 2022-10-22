fun main()
{
    var t = readLine()!!.toInt()
    
    for(i in 0..t - 1)
    {
        var n = readLine()!!.toInt()
        var (a, va) = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
        var (c, vc) = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
        var b = readLine()!!.toInt()
        
        var ans = va + b - a
        
        if(ans > vc)
            ans = vc
            
        println(ans)
    }
}