import java.util.Scanner
import kotlin.system.exitProcess
val read=Scanner(System.`in`)
val k=read.nextInt()
val n=read.nextInt()
val p=Array<Int>(k,{_->read.nextInt()})
val x=Array<Int>(n,{_->read.nextInt()})
fun __gcd(A:Int,B:Int):Int {return if(B!=0){__gcd(B,A%B)}else{A}}
fun binary_search(v:Int):Boolean
{
    var l=0;var r=k-1
    while(l!=r)
    {
        val mid=(l+r) shr 1
        if(p[mid]<v)
            l=mid+1
        else
            r=mid
    }
    return p[l]==v
}
fun test(k1:Int,b1:Int)
{
    var b2=0;var gcd=0
    for(i in 0 until n)
        if((x[i]-b1)%k1!=0)
        {
            if(b2==0)
                b2=x[i]
            else
                gcd=__gcd(x[i]-b2,gcd)
        }
        else{}
    if(b2==0)
    {
        println("YES")
        print(b1);print(' ');println(k1)
        print(b1);print(' ');println(k1)
        exitProcess(0)
    }
    else if(gcd==0)
    {
        println("YES")
        print(b1);print(' ');println(k1)
        print(b2);print(' ');println(k1)
        exitProcess(0)
    }
    else{}
    var lim=Math.sqrt(gcd.toDouble()).toInt()
    for(i in 1..lim)
    {
        if(gcd%i==0)
        {
            if(binary_search(i))
            {
                println("YES")
                print(b1);print(' ');println(k1)
                print(b2);print(' ');println(i)
                exitProcess(0)
            }
            if(binary_search(gcd/i))
            {
                println("YES")
                print(b1);print(' ');println(k1)
                print(b2);print(' ');println(gcd/i)
                exitProcess(0)
            }
        }
    }
}
fun main()
{
    if(n==1)
    {
        println("YES")
        print(x[0]);print(' ');println(p[0])
        print(x[0]);print(' ');println(p[0])
        exitProcess(0)
    }else{}
    if(n==2)
    {
        println("YES")
        print(x[0]);print(' ');println(p[0])
        print(x[1]);print(' ');println(p[0])
        exitProcess(0)
    }else{}
    for(A in 0 until 3)
        for(B in A+1 until 3)
        {
            val V=x[B]-x[A];var pos=0
            for(i in 1..V)
            {
                while(pos!=k&&p[pos]<i)++pos
                if(pos==k)break
                else{}
                if(p[pos]==i&&V%i==0)
                    test(i,x[A])
                else{}
            }
        }
    println("NO")
}