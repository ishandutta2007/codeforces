import java.util.Scanner

fun main(args: Array<String>) {
    val input = Scanner(System.`in`)
    val t = input.nextInt()
    for (sdfadsfasdf in 1..t)
    {
        var a = input.nextInt()
        var b = input.nextInt()
        var p = input.nextInt()
        if (a > b)
        {
            var q = b
            b = a
            a = q
        }
        var f = 0
        for (i in 1..a)
        {
            if (p >= i && p % i == 0 && p / i <= b)
                 f = 1
        }
        if (f == 1)
            println("Yes")
        else
            println("No")
    }
}