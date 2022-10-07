import java.util.*
fun main(args:Array<String>)
{
    val sc = Scanner(System.`in`)
    var t=sc.nextInt()
    var a:String
    var b:String
    for(i in 1..t)
    {
        a=sc.next()
        b=sc.next()
        var n=0
        for(j in a)
            n++
        var m=0
        for(j in b)
            m++
        var k=0
        var flag=0
        var j=0
        while(j<n)
        {
            if(k==m)
            {
                flag=1
                j=n
                continue
            }
            if(a[j]==b[k])
                k++
            else
                if(j!=n-1&&b[k]=='+'&&a[j]=='-'&&a[j+1]=='-')
                {
                    j++
                    k++
                }
                else
                    flag=1
            j++
        }
        if(flag==1||k!=m)
            println("NO");
        else
            println("YES");
    }
}