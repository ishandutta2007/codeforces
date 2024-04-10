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
    var y=sc.nextInt()
    var b=sc.nextInt()
    var r=sc.nextInt()
    var s=min(min(y,b-1),r-2)
    println(s*3+3)
}