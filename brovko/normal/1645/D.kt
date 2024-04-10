fun main()
{
    var n = readLine()!!.toInt()
    
    var a = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
    a.sort()
    
    var b = IntArray(n){0}
    var c = IntArray(n){0}
    
    var x = 0
    var y = 0
    
    for(i in 0..n - 1)
    {
        if(i == 0)
        {
            b[x] = a[i]
            x += 1
        }
        else if(a[i] != a[i - 1])
        {
            b[x] = a[i]
            x += 1
        }
        else
        {
            c[y] = a[i]
            y += 1
        }
    }
    
    var F = 1
    
    for(i in 1..x - 1)
        if(b[i] == b[i - 1])
            F = 0
            
    for(i in 1..y - 1)
        if(c[i] == c[i - 1])
            F = 0
            
    if(F == 0)
        print("NO")
    else
    {
        println("YES")
        
        println(x)
        
        for(i in 0..x - 1)
        {
            print(b[i])
            print(" ")
        }
        
        println()
        println(y)
        
        for(i in 0..y - 1)
        {
            print(c[y - 1 - i])
            print(" ")
        }
    }
}