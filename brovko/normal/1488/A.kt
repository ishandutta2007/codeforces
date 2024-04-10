fun main()
{
    var t = readLine()!!.toInt()
    
    for(i in 0..t - 1)
    {
        var a = readLine()!!.split(" ").map({it.toLong()}).toMutableList()
        var b = 1000000000L
        var ans = 0L
        
        while(b >= 1)
        {
            if(a[1] >= a[0] * b)
            {
                a[1] -= a[0] * b
                ans += 1
            }
            else b /= 10
        }
        
        ans += a[1]
        println(ans)
    }
}