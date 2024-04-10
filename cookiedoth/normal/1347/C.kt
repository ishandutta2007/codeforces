import java.util.Scanner

val D = 10;

fun main(args: Array<String>) {
	val scanner = Scanner(System.`in`)

	var T = scanner.nextInt()

	while ((T--) > 0) {
		var n = scanner.nextInt()

		val ans = mutableListOf<Int> ()
		var pwD = 1
		while (n > 0) {
			var lastDigit = n % D
			if (lastDigit > 0) {
				ans.add(lastDigit * pwD)
			}
			pwD *= D
			n /= D
		}

		println(ans.size)
		ans.forEach {
			print(it)
			print(' ')
		}
		println()
	}
}