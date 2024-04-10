fun main()
{
    var k = readLine()!!.toInt()

    var s = readLine()!!
    var t = readLine()!!
    
    var a = IntArray(k){0}
    
    for(i in 0..k - 1)
        a[i] = s[i].toInt() + t[i].toInt() - 194
        
    for(i in 0..k - 2)
        if(a[k - 1 - i] > 25)
        {
            a[k - 1 - i] -= 26
            a[k - 2 - i] += 1
        }
        
    for(i in 0..k - 1)
    {
        if(a[i] % 2 != 0)
            a[i + 1] += 26
            
        a[i] /= 2
        
        print((a[i] + 97).toChar())
    }
}