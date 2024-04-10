fun main()
{
    var n = readLine()!!.toInt()
    var s = readLine()!!
    
    var x = 0
    var y = 1
    
    while(x < n)
    {
        print(s[x])
        x += y
        y += 1
    }
}