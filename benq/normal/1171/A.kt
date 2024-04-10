fun nextInt() = readLine()!!.toInt()

fun main(args: Array<String>) {
	val t = nextInt()
	for (i in 0..t-1) {
		val x = nextInt()
		println(x/2)
	}
}