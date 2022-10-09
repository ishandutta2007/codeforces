import kotlin.random.Random

val testing = false
var __num = 0
fun ask(nums: IntArray): Int {
    assert(nums.size == 100)
    println("? ${nums.joinToString(" ")}")
    System.out.flush()
    if (testing) {
        val x = __num xor nums[Random.nextInt(100)]
        println("= $x")
        return x
    } else {
        val num = readLine()!!.toInt()
        return num
    }
}
fun answer(num: Int) {
    println("! ${num}")
    System.out.flush()
    if (testing) {
        assert(num == __num)
    }
}
fun solve() {
    val u = ask(IntArray(100) { it + 1 })
    val v = ask(IntArray(100) { (it + 1) shl 7} )
    answer((v and 127) or (u shr 7 shl 7))
}
fun main() {
    if (testing) {
        while (true) {
            __num = Random.nextInt(1 shl 14)
            println("num = $__num")
            solve()
            println("OK")
        }
    } else {
        solve()
    }
}