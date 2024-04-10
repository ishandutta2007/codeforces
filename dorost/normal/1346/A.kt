/*
 * In the name of GOD
 * Who is anything and we're nothing
 * Thanks GOD
 */
import java.util.Scanner

fun main(){
	val input = Scanner(System.`in`)
	var t = input.nextInt()
	for (tc in 1..t){
		var n = input.nextInt()
		var k = input.nextInt()
		var a = 1 + k + k * k + k * k * k
		println(n / a)
		println(n / a * k)
		println(n / a * k * k)
		println(n / a * k * k * k)
	}
}