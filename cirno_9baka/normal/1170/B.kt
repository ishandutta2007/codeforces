import java.util.*

fun main(args:Array<String>)
{
    val sc = Scanner(System.`in`)
    var n=sc.nextInt()
    var mx=0
    var mxx=0
    var s=0
    for(i in 1..n)
    {
        var a=sc.nextInt()
        if(a<mxx)
            s++
        if(mx<a)
        {
            if(mxx<mx)
                mxx=mx
            mx=a
        }
        else
            if(mxx<a)
                mxx=a
    }
    println(s)
}