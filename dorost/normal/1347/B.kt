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
		var a = input.nextInt()
		var b = input.nextInt()
		var c = input.nextInt()
		var d = input.nextInt()
		if ((a == c && b + d == a) || (a == d && b + c == a) || (b == c && a + d == b) || (b == d && a + c == b)){
			println("YES");
		}else{
			println("NO");
		}
	}
}