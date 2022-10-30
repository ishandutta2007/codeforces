import kotlin.math.min

fun main(args: Array<String>) {
	var T = readLine()!!.toInt()
	while (T-->0){
		var (n, k1, k2) = readLine()!!.split(' ').map { it.toInt() }
		var s = readLine()!!
		var sum = 0
		var now = 0
		for(i in 0..n-1){
			if (s[i]=='1'){
				sum+= min(k1, k2-now)
				now= min(k1, k2-now)
			}
			else now=0
		}
		println(sum)
	}
}