fun main()
{
    var t = readLine()!!.toInt()
    
    for(i in 0..t - 1)
    {
        var s = readLine()!!.toString()
        var kl = 0
        var kg = 0
        
        for(j in s)
        {
            if(j == '>')
                kg += 1
                
            if(j == '<')
                kl += 1
        }
        
        if((kl == 0) and (kg == 0))
            println('=')
        else if(kl == 0)
            println('>')
        else if(kg == 0)
            println('<')
        else println('?')
    }
}