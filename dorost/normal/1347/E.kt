/*
	* In the name of GOD
	* Who is anything and we're nothing
	* Thanks GOD
*/
import java.util.Scanner

fun main(){
	val input = Scanner(System.`in`)
	var t = input.nextInt()
	for (i in 1..t){
		var n = input.nextInt()
		if (n == 2 || n == 3){
			println(-1)
			continue
		}
		if (n == 4){
			println("3 1 4 2 ")
			continue
		}
		for (i in 1..(n / 2))
			println(i * 2)
		println(n / 2 * 2 - 3)
		if (n % 2 == 1){
			println(n / 2 * 2 + 1)
		}
		println(n / 2 * 2 - 1)
		var x = n / 2 * 2 - 5
		while (x > 0){
			println(x)
			x = x - 2
		}
	}
}