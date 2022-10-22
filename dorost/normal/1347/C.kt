/*
	* In the name of GOD
	* Who is anything and we're nothing
	* Thanks GOD
*/
import java.util.Scanner

fun main(){
	var t = readLine()!!.toInt()
	for (i in 1..t){
		var a = readLine()!!
		var n = a.length
		var ans = 0
		for (i in 0..(n - 1)){
			if (a[i] != '0'){
				ans = ans + 1;
			}
		}
		println(ans)
		for (i in 0..(n - 1)){
			if (a[i] != '0'){
				print(a[i])
				for (j in 0..(n - i - 2))
					print("0")
				print(" ")
			}
		}
		println("")
	}
}