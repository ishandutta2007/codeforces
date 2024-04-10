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
		var k1 = input.nextInt()
		var k2 = input.nextInt()
		var s = input.next()
		var i = 0
		var ans = 0
		var an = 0
		while (i < n - 1){
			if (s[i] == '1' && s[i + 1] == '1'){
				an ++
				i++
			}
			i++
		}
		for (j in 0..(n - 1)){
			if (s[j] == '1')
				ans++
		}
		if((ans * k1 < (ans - (an * 2)) * k1 + an * k2)){
			println(ans * k1)
		}else{
			println((ans - (an * 2)) * k1 + an * k2)
		}
	}
}