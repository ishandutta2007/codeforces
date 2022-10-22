import java.util.Scanner
 
fun main(args: Array<String>) {
    val input = Scanner(System.`in`)
    val t = input.nextLine().toInt()
 
    for (x in 0 until t) {
        val line = input.nextLine()
        val (a, b) = line.split(' ').map { it.toInt() }
        print(a/(1+b+b*b+b*b*b))
        print(" ")
        print(a/(1+b+b*b+b*b*b)*b)
        print(" ")
        print(a/(1+b+b*b+b*b*b)*b*b)
        print(" ")
        println(a/(1+b+b*b+b*b*b)*b*b*b)
    }
}