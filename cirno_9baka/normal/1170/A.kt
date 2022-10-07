import java.util.*

fun min(a:Int,b:Int):Int
{
    if(a<b)
        return a
    else
        return b
}

fun main(args:Array<String>)
{
    val sc = Scanner(System.`in`)
    var t=sc.nextInt()
    for(i in 1..t)
    {
        var a=sc.nextInt()
        var b=sc.nextInt()
        var s=min(a,b);
        print(s-1);
        print(' ');
        print(a-s+1);
        print(' ');
        print(b-s+1);
        print('\n');
    }
}