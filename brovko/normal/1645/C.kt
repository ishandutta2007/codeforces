fun main()
{
    var n = readLine()!!.toInt()
    
    var a = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
    a.sort()
    
    var ans = 0
    
    for(i in 0..n / 2 - 1)
        ans += a[2 * i + 1] - a[2 * i]
        
    print(ans)
}