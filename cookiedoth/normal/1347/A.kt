import java.util.Scanner

fun main(args: Array<String>) {
	val scanner = Scanner(System.`in`)

	var T = scanner.nextInt()

	while ((T--) > 0) {
		var a:Int = scanner.nextInt()
		var b:Int = scanner.nextInt()
		println(a + b)
	}
}