/*
 * In the name of GOD
 * Who is anything and we're nothing
 * Thanks GOD
 */
import java.util.*
	fun main() {
		var t = readLine()!!.toInt()
			while(t -- > 0){
				var n = readLine()!!.toInt()
				var a = readLine()!!.split(" ").map { it.toInt() }
				var max = 0
				var i = 0
				var j = n - 1
				var x = 0
				var y = 0
				var z = 0
				while(i <= j){
					var cur=0
					z++
					while(cur <= max && i <= j){
						cur += a[i]
						i ++
					}
					x += cur
					max = cur
					if(i > j)
							break
					z++
					cur=0
					while(cur <= max && i <= j){
						cur += a[j]
						j--
					}
					y += cur
					max = cur
				}
				print(z)
				print (" ")
				print (x)
				print (" ")
				print (y)
				println("")
			}
	}