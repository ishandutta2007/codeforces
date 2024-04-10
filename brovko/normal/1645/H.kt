fun main()
{
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
    
    var x = IntArray(200005){0}
    var y = IntArray(200005){0}
    var ax = IntArray(200005){0}
    var ay = IntArray(200005){0}
    var ans = IntArray(200005){0}
    var px = IntArray(200005){0}
    var py = IntArray(200005){0}
    
    var N = 200005
    
    x[0] = -1
    y[0] = -1
    ax[0] = N
    ay[0] = N

    for(i in 0..n - 1)
    {
        x[i + 1] = a[i]

        ax[i + 1] = -1

        if((x[i] < a[i]) and (ax[i] > ax[i + 1]))
        {
            ax[i + 1] = ax[i]
            px[i + 1] = 0
        }

        if((y[i] < a[i]) and (ay[i] > ax[i + 1]))
        {
            ax[i + 1] = ay[i]
            px[i + 1] = 1
        }

        ay[i + 1] = a[i]

        y[i + 1] = N

        if((ax[i] > a[i]) and (x[i] < y[i + 1]))
        {
            y[i + 1] = x[i]
            py[i + 1] = 0
        }

        if((ay[i] > a[i]) and (y[i] < y[i + 1]))
        {
            y[i + 1] = y[i]
            py[i + 1] = 1
        }
    }

    if(((x[n] > 200000) or (ax[n] == -1)) and ((y[n] > 200000) or (ay[n] == -1)))
        print("NO")
    else
    {
        println("YES")

        var f = 0

        if((x[n] > 200000) or (ax[n] == -1))
            f = 1
            
        var i = n

        while(i > 0)
        {
            ans[i - 1] = f

            if(f == 0)
                f = px[i]
            else f = py[i]
            
            i -= 1
        }

        for(z in 0..n - 1)
        {
            print(ans[z])
            print(" ")
        }
    }

    
}