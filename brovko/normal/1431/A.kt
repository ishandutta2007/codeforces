fun main()
{
    var t = readLine()!!.toLong()
    
    for(i in 0..t - 1)
    {
        var n = readLine()!!.toInt()
        var a = readLine()!!.split(" ").map({it.toLong()}).toMutableList()
        a.sort()
        
        var ans = 0L
        
        for(j in 0..n - 1)
        {
            if((n - j) * a[j] > ans)
                ans = (n - j) * a[j]
        }
        
        println(ans)
    }
}