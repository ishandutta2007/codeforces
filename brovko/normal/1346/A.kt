fun main()
{
    var t = readLine()!!.toInt()
    
    for(iosv in 0..t - 1)
    {
        var (n, k) = readLine()!!.split(" ").map({it.toInt()})
        
        var n1 = 1
        var n2 = k
        var n3 = k * k
        var n4 = k * k * k
        
        var mul = n / (n1 + n2 + n3 + n4)
        
        print(n1 * mul)
        print(" ")
        print(n2 * mul)
        print(" ")
        print(n3 * mul)
        print(" ")
        println(n4 * mul)
    }
}