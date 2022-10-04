import java.util.Scanner

var a1 = 0
var a2 = 0
var b1 = 0
var b2 = 0

fun can(): Boolean {
	return ((a1 + a2 == b1 && b1 == b2) || (b1 + b2 == a1 && a1 == a2));
}

fun printAB() {
	println(a1)
	println(b1)
	println(a2)
	println(b2)
}

fun main(args: Array<String>) {

	val scanner = Scanner(System.`in`)

	var T = scanner.nextInt()

	while ((T--) > 0) {
		a1 = scanner.nextInt()
		b1 = scanner.nextInt()
		a2 = scanner.nextInt()
		b2 = scanner.nextInt()
		var res = false
		res = (res || can())
		a1 = b1.also { b1 = a1 }
		res = (res || can())
		a2 = b2.also { b2 = a2 }
		res = (res || can())
		a1 = b1.also { b1 = a1 }
		res = (res || can())
		if (res) {
			println("Yes")
		} else {
			println("No")
		}
	}
}