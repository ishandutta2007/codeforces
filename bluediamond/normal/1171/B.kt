import java.util.*

fun main(args: Array<String>){
    var sc = Scanner(System.`in`)
    var a = sc.nextLong()
    var b = sc.nextLong()
    var c = sc.nextLong()
    if (b - 1 < a) {
        a = b - 1
    }
    if (c - 2 < a) {
        a = c - 2
    }
    println(3 * a + 3)
}