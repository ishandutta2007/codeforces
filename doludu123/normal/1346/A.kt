import java.util.Scanner
val input = Scanner(System.`in`)
 
fun main () {
    var t = input.nextInt()
    while (t --> 0) {
        var n = input.nextInt()
        var k = input.nextInt()
        var aa = n / (1 + k + k * k + k * k * k)
        print("${aa} ")
        print("${aa * k} ")
        print("${aa * k * k} ")
        print("${aa * k * k * k} ")
        println()
    }
}